#include "stdio.h"
#include "string.h"
/* error
	about the 描述
*/
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		char s[81];
		scanf("%s",s);
		int len=strlen(s);
		int j,i,yes=0;
		for (i = 1; i <(len/2)%2?len/2:len/2+1; ++i)
		{
			for (j = 0; j < len-i; ++j)
			{
				if(s[j]!=s[j+i]) break;
			}
			if(j==len-i){
				if(len%i != 0){//233333333333//todo
					printf("%d\n",len);//wtf???
				}else{


				printf("%d\n",i);
			}
				yes=1;
				break;
			}
		}

		if(yes==0){
			printf("%d\n",len);//wtf???
		}
		if(T) printf("\n");
	}
	return 0;
}