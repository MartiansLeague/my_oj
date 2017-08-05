/*
The Goods And Store.
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
Some logic and function for good.
商品与仓储信息。
*/

#include "goods.h"

Store * InitStore() {
	Store *s;
	s = MAKE(Store);
	s->L = LinkListInit();/*存放商品的链表*/
	StoreInfo *si;
	si = MAKE(StoreInfo);/*额外信息*/
	s->L->elem = si;
	return s;
}
int AddGoods(Store s, int id, char * name, int count) {
	goods * g;
	g = MAKE(goods);
	g->id = id;
	strcpy(g->name, name);
	g->count = count;
	pushfront(s.L, g);
	return OK;
}

int ChangeGoodsName(Store s, int id, char * name) {
	goods *g;
	g = FindGoodsById(s, id);
	if (g == NULL) {
		return CHANGEFINDERROR;
	}
	strcpy(g->name, name);
	return CHANGEOK;
}

int ChangeGoodsCount(Store s, int id, int count) {

	goods *g;
	g = FindGoodsById(s, id);

	if (g == NULL) {
		return CHANGEFINDERROR;
	}
	g->count = count;
	return CHANGEOK;
}

/*id的比较函数*/
int cmpid(goods *g, StoreInfo * si) {
	/*在storeinfo里面读取期望的id值*/
	return g->id == si->waitid;
}
/*名字的比较函数*/
int cmpname(goods *g, StoreInfo * si) {
	return strcmp(g->name, si->waitname) == 0;
}

/*寻找第一个满足比较函数的节点*/
int find(LinkList L, ptr p, int(*cmp)(goods *, StoreInfo *)) {
	return (cmp(p, L->elem));
}

goods * getgood(LinkNode *p) {
	if (p == NULL) 
		return NULL;
	return p->elem;
}
LinkNode * FindLinkNodeById(Store s, int id) {
	StoreInfo * si;
	si = s.L->elem;
	si->waitid = id;/*将期望的id存进去，比较函数才能获取到*/
	return foreachwithcmp(s.L, find, cmpid);;
}

goods * FindGoodsById(Store s, int id) {
	LinkNode * p;
	/* note : it return last node ,so you must use R(p) to get correct node*/
	p = R(FindLinkNodeById(s, id));
	return getgood(p);
}

LinkNode * FindLinkNodeByName(Store s, char * name) {
	StoreInfo * si;
	si = s.L->elem;
	si->waitname = name;/*同理*/
	return foreachwithcmp(s.L, find, cmpname);;

}
goods * FindGoodsByName(Store s, char *name) {
	LinkNode * p;
	/* note : it return last node ,so you must use R(p) to get correct node*/
	p = R(FindLinkNodeByName(s, name));
	return getgood(p);
}

int freegood(goods * g) {
	free(g);
	return 0;
}

int RemoveGoodsById(Store s, int id) {
	LinkNode * p;

	p = FindLinkNodeById(s, id);/*last node*/
	if (p == NULL) {
		return REMOVENULL;
	}
	RemoveNode(p, freegood);
	return 0;
}

int RemoveGoodsByName(Store s, char *name) {
	LinkNode * p;

	p = FindLinkNodeByName(s, name);/*last node*/
	if (p == NULL) {
		return REMOVENULL;
	}
	RemoveNode(p, freegood);
	return OK;
}

/*不带比较函数的遍历*/
int printgoods(LinkList L, ptr p) {
	goods *g;
	g = (goods*)p;
	printf("id:%05d\tname:%-10s\tcount:%05d\n", g->id, g->name, g->count);
	return 0;
}
int ShowAllGoods(Store s) {
	foreach(s.L, printgoods);
	return 0;
}

int sumcount(LinkList L, ptr p) {
	StoreInfo * si;
	si = L->elem;
	goods *g;
	g = (goods*)p;
	si->sumconut += g->count;
	return 0;
}

int SumCount(Store s) {
	StoreInfo *si;
	si = s.L->elem;
	si->sumconut = 0;/*保留信息咯*/
	foreach(s.L, sumcount);
	return si->sumconut;
}

int sumid(LinkList L, ptr p) {
	StoreInfo * si;
	si = L->elem;
	si->sumconut += 1;
	return 0;
}
int SumId(Store s) {
	StoreInfo *si;
	si = s.L->elem;
	si->sumconut = 0;
	foreach(s.L, sumid);
	return si->sumconut;
}

/*从文件读取商品信息*/
goods * goodreader(FILE *fp) {
	goods* g;
	g = MAKE(goods);
	if (fread(g, sizeof(goods), 1, fp))
		return g;
	return 0;
}
/*写入商品信息*/
int goodswriter(FILE * fp, goods *g) {
	fwrite(g, sizeof(goods), 1, fp);
	return 0;
}