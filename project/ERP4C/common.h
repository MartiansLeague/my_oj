/*
Common Library.
Author czfshine (https://github.com/czfshine)
Date :2017-05-18 21:12
Langage :ANSI C
Listen :MIT
Description:
通用函数与变量，基础设施。
*/
#ifndef COMMON_H
#define COMMON_H
/*分配内存*/
#define MAKE(type) (type * ) malloc(sizeof(type));

#define LOOP(fn) while(!fn()){};

#endif