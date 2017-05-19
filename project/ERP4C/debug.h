/*
Debug Library.
Author czfshine (https://github.com/czfshine)
Date :2017-05-18 21:12
Langage :ANSI C
Listen :MIT
Description:
调试库。
*/

/*在开发编译时把LOCAL宏打开，进入调试模式*/
#ifndef LOCAL
int DEBUG = 0;
#else
int DEBUG = 1;
#endif 

/*在文件输入输出环境下测试，然后将控制权交由用户*/
#ifdef __linux__ || __linux
#define WithDebug(code) code;
#else
#define WithDebug(code) do{\
	if(DEBUG){\
		/*保留原始stdout，不然输出会乱码*/\
		int oldstdout = _dup(1);\
		freopen("testin1.txt", "r", stdin);\
		freopen("testout1.txt", "w", stdout);\
		code;\
		freopen("CON", "r", stdin);\
		freopen("CON", "w", stdout);\
		_dup2(oldstdout, 1);\
	} \
		code;\
}while (0);
#endif
