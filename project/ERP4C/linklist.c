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
#include "linklist.h"
#include "common.h"

LinkList LinkListInit() {
	/*初始化*/
	LinkNode *n;
	n = newnode(NULL);
	n->next = NULL;
	return n;
}

LinkNode * newnode(ptr elem) {
	/*生成元素为elem的节点*/
	LinkNode * n;
	n = MAKE(LinkNode);
	n->elem = elem;
	n->next = NULL;
	return n;
}
LinkNode * back(LinkList L) {
	/*取最后一个节点（可能为头节点）*/
	LinkNode * temp;
	temp = L;
	while (temp->next) 
		temp = temp->next;
	return temp;
}
int pushback(LinkList L, ptr elem) {

	/**/
	/*尾部插入，复杂度O(n)*/
	/**/

	LinkNode * n;
	n = newnode(elem);
	LinkNode * temp;
	temp = back(L);
	temp->next = n;
	return 0;
}

int pushfront(LinkList L, ptr elem) {
	/*在前端插入，复杂度O(1)*/
	LinkNode * n, *p;
	n = newnode(elem);
	p = L->next;
	L->next = n;
	n->next = p;
	return 0;
}

LinkNode* foreach(LinkList L, int(*fn)(LinkList, ptr)) {
	/*遍历链表，直到fn返回非0*/
	/* note : it return last node ,so you must use R(p) to get correct node*/
	/*注意：它返回的是前一个节点，用以删除操作，正确节点得用 R()宏进行修正*/
	/*until fn()!=0 return the Node*/
	LinkNode *p;
	p = L;
	if (L->next == NULL) return NULL;
	while (p->next) {
		LinkNode * a = p->next;
		ptr b = a->elem;
		if (fn(L, b)) 
			return p;/*here*/
		p = p->next;
	}
	return NULL;
}


LinkNode* foreachwithcmp(LinkList L, int(*fn)(LinkList, ptr, cmpfn(cmp)),cmpfn(cmp)) {
	/*带比较函数的遍历*/

	LinkNode *p;
	p = L;

	while (p->next) {
		LinkNode * a = p->next;
		ptr b = a->elem;
		if (fn(L, b, cmp)) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int freeNode(LinkNode * nn, int(*freeelem)(ptr)) {
	/*释放节点*/
	freeelem(nn->elem);/* perevent memnory leak*/
	free(nn);
	return 0;
}

int RemoveNode(LinkNode *p, int(*freeelem)(ptr)) {
	/* remove the next node*/
	if (p->next == NULL)
		return 0;
	LinkNode *nn;
	nn = p->next;/*correct node to remove*/
	if (nn->next == NULL) 
		p->next = NULL;/* must be set success*/
	else 
		p->next = nn->next;
	return freeNode(nn, freeelem);
}