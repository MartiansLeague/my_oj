/*
Serialize Linklist .
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
seralize and unseralize linklist to/from file.
序列化和反序列化链表
*/
#include "serialize.h"

int pretretment(LinkList L, ptr p, writerfn(writer)) {
	/*预处理*/
	StoreInfo *si;
	si = L->elem;
	return writer(si->file, p);
}

int serialize(Store s, FILE * fp, writerfn(writer)) {
	/*序列化进文件*/
	SI(s)->file = fp;
	foreachwithcmp(s.L, pretretment, writer);
	return 0;
}

int unserialize(Store s, FILE * fp, readfn(reader)) {
	/*反序列化*/
	/*注意：反序列化后顺序颠倒，因为用了pushfront，用pushback复杂度会变大，但是顺序不会改变*/
	/*TODO：可优化*/
	void * elem;
	while (elem = reader(fp)) {
		pushfront(s.L, elem);
	}
	return 0;
}
