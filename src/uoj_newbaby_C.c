#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kcase = 0; kcase < T; ++kcase)
	{
		int A,D;
		char B[102];

		//too young too simple
		//scanf("%d.%se%d",&A,B,&D);
		//printf("%d%s%d",A,B,D);

		scanf("%d",&A);
		char ch;
		int cur=0;
		getchar();
		while((ch=getchar())!='e')
			B[cur++]=ch;
		B[cur]='\0';

		scanf("%d",&D);
		printf("%d%s%d\n",A,B,D);

		int len=strlen(B);

		if(len>D){
			int sub=len-D;
			printf("%d",A);
			int i;
			for (i = 0; i < D; ++i)
			{
				printf("%c",B[i]);
			}
			printf(".");
			for (int j = 0; j < sub; ++j)
			{
				printf("%c",B[D+j]);
			}
		}
	}
	return 0;
}