/*
General Linklist Library.
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
	The general linklist,other infomation to see code .
	通用链表库，支持链表的增删查改寻。
*/
#ifndef LINKLIST_H
#define LINKLIST_H 
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*通用指针*/

#define ptr void *


/*取正确的节点*/
#define R(p) (((p)==NULL)?NULL:((p)->next))


typedef struct LinkNode
{
	ptr elem;
	struct LinkNode *next;
}  LinkNode, *LinkList;
#define cmpfn(cmp)  int(*cmp)(ptr, ptr)

LinkList  LinkListInit();/*初始化*/
LinkNode * newnode(ptr elem);/*新节点*/
LinkNode * back(LinkList L);/*返回最后一个节点*/
int pushback(LinkList L, ptr elem);/*加到最后*/
int pushfront(LinkList L, ptr elem);/*加到最前*/
LinkNode * foreach(LinkList L, int(*fn)(LinkList, ptr));/*遍历*/
LinkNode * foreachwithcmp(LinkList L, int(*fn)(LinkList, ptr, cmpfn(cmp)), cmpfn(cmp));/*带比较函数的遍历*/
int RemoveNode(LinkNode *p, int(*freeelem)(ptr));/*删除节点*/
#endif
