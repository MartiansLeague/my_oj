/*

**************************************
10677 我们仍未知道那天所看见的花的名字
**************************************
Description

    芽间、仁太、波波、安鸣、雪集、鹤见是昔日孩童时期总是一起结伴同玩的6位好朋友。自从小时候的一次意外后，大家的关系渐行渐远。

随着时间的流逝，大家都为了自己的生活和理想各奔东西。

    某天，芽间要离开大家了，她给大家各留下了一封电子邮件。这时候，在名牌高中读书的雪集，仗着自己的电脑知识，

把给仁太电子邮件内容（一句话）加密了。

然后他留下了一段加密程序，因为他想看看读普通学校的仁太能不能解密出来的。

    但事实证明，学校的名牌与否不是最重要的，重要的是自己个人的努力。为了看到芽间给自己的信，仁太专门去学了C语言，

然后把那句话解密出来了。你也能做到吗？


**************************************
Input

以下是雪集的加密代码：

void Encrypt(char msg[])

{

	char key[] = "sleepiforest";

	int msgLen = strlen(msg);

	int keyLen = strlen(key);

	int offset;

	for(offset=0;offset<msgLen;++offset)

	{

		msg[offset] ^= key[offset%keyLen]; // ^是异或运算

	}

	for(offset=0;offset<msgLen;++offset)

	{

		printf("%02x ",msg[offset]); //%x是十六进制

	}

}

芽间的邮件里的内容msg传入上面的函数后，得到以下的输出。

53 30 39 59 0e 48 18 4f 34 0a 01 13 16 18 48 28 15 44 28 00 06 45 0d 55 0d 52 4a 4a 50你能把msg的原文输出解密出来吗？


**************************************
Output

根据加密程序，把这句话解密，然后输出出来即可。

例如：假设解密出来的这句话是“WELCOME TO THE TEAM OF SCAU_ACM”。

那么你只需要把这句话输出就可以了。

提供一个模板:

#include <stdio.h>

int main()

{

	char msg[] = "WELCOME TO THE TEAM OF SCAU_ACM";

	puts(msg);

	return 0;

}

只需要把msg里的内容换成你解密出来的内容，提交即可通过。


**************************************
Sample Input

无
**************************************
Sample Output

根据题目要求输出
**************************************
Hint

一个字符也不能漏，不能错哦~~所以呢~~最好还是在解密程序里把解密后的串输出吧~~

提供一个录入数据的代码：

char bin[] = "53 30 39 59 0e 48 18 4f 34 0a 01 13 16 18 48 28 15 44 28 00 06 45 0d 55 0d 52 4a 4a 50";

char msg[50];

int len = (strlen(bin)+1)/3;

for(int i=0;i<len;++i)

{

	这里可以用sscanf把bin内的数据录入到msg~~具体用法大家查资料吧~~

}


**************************************
Source
**************************************
Author0*/
#include "stdio.h"
#include "string.h"
void Encrypt(char msg[])
{
	char key[] = "sleepiforest";
	int msgLen = strlen(msg);
	int keyLen = strlen(key);
	int offset;
	for(offset=0;offset<msgLen;++offset)
	{
		msg[offset] ^= key[offset%keyLen]; // ^是异或运算
	}
	for(offset=0;offset<msgLen;++offset)
	{
		printf("%02x ",msg[offset]); //%x是十六进制
	}
}

void Decrypt(char *msg){

	char bin[] = "53 30 39 59 0e 48 18 4f 34 0a 01 13 16 18 48 28 15 44 28 00 06 45 0d 55 0d 52 4a 4a 50";
	int len = (strlen(bin)+1)/3,d;
	char key[] = "sleepiforest";
	int keyLen = strlen(key);
	for(int i=0;i<len;++i)
	{	sscanf(bin+i*3,"%x",&d);
        printf("%x\n", d);
		msg[i] = d^key[i%keyLen];
	}
	msg[len]='\0';

}
int main(int argc, char const *argv[])
{
	//char msg[50];
	//Decrypt(msg);
	puts(" \\\\<~!~ Forget-Me-Not ~!~>// ");//wtf??
	return 0;
}