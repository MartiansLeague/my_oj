#include "stdio.h"
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int a;
	scanf("%d",&a);
	a=a*a;
	printf("1");
	for (int i =a%2; i < a; i+=2)
	{a%i;printf("1");

		if((a%i)==0){
			printf("1");
			int c=(i+a/i)/2;
			int b=abs((i-a/i)/2);
			printf("1");
			if(b*b+a==c*c&& b!=0)
				printf("%d %d\n",b,c);
		}

	}
	return 0;
}