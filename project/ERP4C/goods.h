/*
The Goods And Store.
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
Some logic and function for good.
商品相关的函数声明
*/
#ifndef GOODS_H
#define GOODS_H 

#include <stdio.h>
#include <string.h>
#include "common.h"
#include "linklist.h"

typedef struct {
	int id;
	int count;
	char name[255];
} goods;

typedef struct {
	LinkList L;
}	Store;/*仓储*/

typedef struct {
	int waitid;
	char * waitname;
	int sumconut;
	FILE *file;
}	StoreInfo;/*不想污染全局作用域，存放额外信息*/


#define CANTFIND 0;

#ifndef CHANGEOK
#define CHANGEOK 0
#endif

#ifndef CHANGEFINDERROR
#define CHANGEFINDERROR 1
#endif

#ifndef OK
#define OK 0
#endif

#ifndef ERROR
#define ERROR 1
#endif

#define REMOVENULL -1

/*快速取storeinfo*/
#define SI(s) ((StoreInfo*)(s.L)->elem)
Store * InitStore();
int AddGoods(Store s, int id, char * name, int count);
int ChangeGoodsName(Store s, int id, char * name);
int ChangeGoodsCount(Store s, int id, int count);
goods * FindGoodsById(Store s, int id);
goods * FindGoodsByName(Store s, char *name);
int ShowAllGoods(Store);
int RemoveGoodsById(Store s, int id);
int RemoveGoodsByName(Store s, char *name);

int SumCount(Store s);
int SumId(Store s);
goods * goodreader(FILE * fp);/*读取器*/
int goodswriter(FILE * fp, goods * g);/*写入器*/
#endif