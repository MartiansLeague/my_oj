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

#ifndef SERIALIZE_H
#define SERIALIZE_H
#include "goods.h"
#include "linklist.h"


/*节点写入函数*/
#define writerfn(name) int(* name)(FILE* ,void *)
/*节点读取函数*/
#define readfn(name)	void*(*name)(FILE *)

int serialize(Store s, FILE * fp, writerfn(writer));

int unserialize(Store s, FILE * fp, readfn(reader));

#endif