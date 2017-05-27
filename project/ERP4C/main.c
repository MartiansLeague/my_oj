/*
THE ERP SYSTEM FOR C (ERP4C)
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
商品进销存管理程序
1、题目描述
   设计一个商品进销存管理程序，该程序具有以下功能：
   （1）录入商品信息；
   （2）给定商品编号，修改该商品信息；
   （3）给定商品编号，删除该商品信息；
   （4）录入商品的进货与销售信息；
   （5）给定商品编号或商品名，查看该商品及库存信息；
   （6）统计功能：提供一些统计各类信息的功能。
2、题目要求
   （1）按照分析、设计、编码、调试和测试过程完成应用程序；
   （2）学习并使用流程图等工具，并在撰写报告中使用；
   （3）程序的各项功能在程序运行时，以菜单方式选择并执行；
   （4）要求用户输入数据时，要给出清晰、明确的提示，包括：输入数据的内容、格式及结束方式等
   （5）所有的信息存储在一个文件或多个中，并实现文件读写操作。
   （6）程序中用链表存放商品及进销存信息并实现增删减功能。（必须）
3、提示
   （1）提醒事件信息可以设计一个结构体类型
   （2）自己构思并增加的除规定功能之外的新功能，酌情加分。

*/

#include "tui.h"
#include "goods.h"
#include "main.h"
#include <stdio.h>
#ifndef __linux__ || __linux
#include <io.h>
#endif 

#include "debug.h"
#include "serialize.h"
#include "common.h"

void Init() {
	Store * S;
	S = InitStore();
	GobalStore = *S;

	FILE *fp;
	fp = fopen("goods.dat", "rb");
	if (fp == NULL) {
		/*文件不存在则创建*/
		fp = fopen("goods.dat", "wb");
		fclose(fp);
	}
	else {
		SI(GobalStore)->file = fp;
		unserialize(GobalStore, fp, goodreader);
		fclose(fp);
	}
}

void GarbageCollection() {
	/*垃圾回收，不过就这个程序而言，内存不用手动释放，*/
	/*因为调用这个函数时程序都准备结束了，交给操作系统处理。*/
	FILE *fp;
	fp = fopen("goods.dat", "wb");
	serialize(GobalStore, fp, goodswriter);
	fclose(fp);
}
void callback() {
	/*测试用回调函数*/
	printf("test callback");
}

goods * WantGoodsById(int * res) {
	/*请求用户输入id，并返回对应的商品*/
	int id;
	id = WantId();
	if (id == 0) {
		ToMainScreen();
		return -1;
	}
	*res = id;/*保留，交给调用者*/
	return FindGoodsById(GobalStore, id);;

}

int LogginGoods() {
	/*录入商品信息*/
	ToLogginScreen();
	char * name;
	int id, count;

	goods *g;
	g = WantGoodsById(&id);
	if (g == -1) return 1;
	if (g != NULL) {
		ShowGoodsExist(id);
		WantEnter();
		return 0;
	}
	name = WantName();
	count = WantCount();

	AddGoods(GobalStore, id, name, count);

	ShowLogginSuccess();
	WantEnter();
	return 0;
}

int ChangeName(goods* g) {
	char * name;
	name = WantName();
	strcpy(g->name, name);
	return 0;
}

int ChangeCount(goods * g) {
	int count;
	count = WantCount();
	g->count = count;
	return 0;
}

int ChangeGoods() {
	/*修改商品信息*/
	ToChangeScreen();

	int id;
	goods * g;
	g = WantGoodsById(&id);

	if (g == (goods *)-1) return 1;
	if (g == NULL) {
		ShowCantFind(id);
		WantEnter();
		return 0;
	}

	ShowChangeType();

	int type = -1;
	while (type < 0 || type>2) {
		type = WantNum();
		switch (type) {
		case CHANGENAME:ChangeName(g); break;
		case CHANGECOUNT:ChangeCount(g); break;
		default: {ShowInputTypeError(); ShowChangeType(); }
		}
	}
	ShowChangeSuccess();
	WantEnter();
	return 0;
}

int RemoveById() {
	int id;
	id = WantId();
	if (RemoveGoodsById(GobalStore, id) == REMOVENULL) {
		ShowRemoveNull();
		WantEnter();
		return ERROR;
	}
	return OK;
}

int  RemoveByName() {
	char *name;
	name = WantName();
	if (RemoveGoodsByName(GobalStore, name) == REMOVENULL) {
		ShowRemoveNull();
		WantEnter();
		return ERROR;
	}
	return OK;
}
int RemoveGoods() {
	/*删除商品*/
	ToRemoveScreen();

	int type = -1;
	while (type < 0 || type>2) {
		type = WantNum();
		switch (type) {
		case REMOVEBYID:if (RemoveById()) return 0; break;
		case REMOVEBYNAME:if (RemoveByName()) return 0; break;
		case REMOVETOEXIT: ToMainScreen(); return 1;
		default: {ShowInputTypeError(); WantEnter(); ToRemoveScreen(); }
		}
	}

	ShowRemoveSuccess();
	WantEnter();
	return 0;
}

int QueryGoods() {
	/*列出商品信息*/
	ToQueryScreen();
	if (GobalStore.L->next == NULL)
	{
		ShowStoreEmpty();
		return 1;
	}
	ShowAllGoods(GobalStore);
	WantEnter();
	ToMainScreen();
	return 1;
}

int  SaleGoods() {
	ToSaleScreen();

	int id;
	id = WantId();
	if (id == 0) 
		return EXIT;
	goods *g;
	g = FindGoodsById(GobalStore, id);
	if (g == NULL)
		return GOODNOTFOUND;

	int sc;
	ShowSaleCount();
	sc = WantNum();

	if (g->count - sc < 0) 
		return GOODSCOUNTLESS;
	else {
		g->count -= sc;
		ShowSaleSuccess();
		WantEnter();
	}
	
	return OK;
}


int StockGoods() {
	ToStockScreen();

	int id;
	id = WantId();
	if (id == 0) {
		return EXIT;
	}

	goods *g;
	g = FindGoodsById(GobalStore, id);
	if (g == NULL)
		return GOODNOTFOUND;

	int sc;
	ShowStockCount();
	sc = WantNum();
	g->count += sc;

	ShowStockSuccess();
	WantEnter();
	return OK;
}

int  Loggin2S() {
	/*售出与进货信息*/
	ToLoggin2SScreen();

	int type = -1;
	while (type < 0 || type>2) {
		type = WantNum();
		switch (type) {
		case SALE:
			switch (SaleGoods()) {
			case  GOODNOTFOUND: {
				ShowGoodNotFound();
				WantEnter();
				break;
			}
			case GOODSCOUNTLESS: {
				ShowGoodsCountLess();
				WantEnter();
				break;
			}
			}
			break;
		case STOCK:if (StockGoods() == GOODNOTFOUND) { ShowGoodNotFound(); WantEnter(); }; break;
		case EXIT: ToMainScreen(); return 1;
		default: {ShowInputTypeError(); WantEnter(); ToLoggin2SScreen(); }
		}
	}

	return 0;
}


void PrintSumCount() {
	ShowSumCount();
	printf("%d\n", SumCount(GobalStore));
	WantEnter();
}

void PrintIdCount() {
	ShowIdCount();
	printf("%d\n", SumId(GobalStore));
	WantEnter();
}

int StatisGoods() {
	/*统计货品信息*/
	ToStatisScreen();

	int type=-1;

	while (type < 0 || type>2) {
		type = WantNum();
		switch (type) {
		case SHOWSUMOFCOUNT:PrintSumCount(); break;
		case SHOWCOUNTID:PrintIdCount(); break;
		case EXIT: ToMainScreen(); return 1;
		default: {ShowInputTypeError(); WantEnter(); ToStatisScreen(); }
		}
	}
	return 0;
}

int ListenMainKey() {
	/*监听用户输入*/
	int op;
	op = WantNum();

	switch (op) {/*错误检查*/
	case WANTTYPEERROR:
		MainWantError(TypeError, T_NUM);
	case WANTNULLERROR:
		MainWantError(TypeNullError, T_NUM);
	case WANTLONGERROR:
		MainWantError(TypeLongError, T_NUM);
	}

	MENU(op)
		MENUITEM(MENULOGGIN, LOOP(LogginGoods));
		MENUITEM(MENUCHANGE, LOOP(ChangeGoods));
		MENUITEM(MENUREMOVE, LOOP(RemoveGoods));
		MENUITEM(MENULOG2S, LOOP(Loggin2S));
		MENUITEM(MENUQUERY, LOOP(QueryGoods));
		MENUITEM(MENUSTATIS, LOOP(StatisGoods));
		MENUITEM(MENUHELP, ShowHelp());
		MENUITEM(MENUEXIT, return 1);
	DEFAULTITEM(ShowInputTypeError(); WantEnter(); ToMainScreen(); return 0;);

	return 0;
}

int main(int argn, char * argv[]) {
	Init();

	WithDebug({
		ToMainScreen();
		LOOP(ListenMainKey);
		SayGoodbye();
		GarbageCollection();
	});
	return 0;
}
