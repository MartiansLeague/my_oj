#include "stdio.h"	
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for (int i = -n; i <= n; ++i)
	{
		for (int j = 0; j < abs(i); ++j)
			printf(" ");
		printf("*");
		if(abs(i)!=n)
			for (int j= 0; j < (n-abs(i))*2-1; ++j)
				printf(" ");
		if(abs(i)!=n) printf("*");
		for (int j = 0; j < abs(i)*2-1; ++j)
			printf(" ");
		if(i) printf("*");
		if(abs(i)!=n)
			for (int j= 0; j < (n-abs(i))*2-1; ++j)
				printf(" ");
		if(abs(i)!=n) printf("*");
		printf("\n");
	}
	return 0;
}