#include "stdio.h"

#define N 6

int main(int argc, char const *argv[])
{
	char data[6]={'0','1','2','3','4','5'};
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				printf("%c%c%c\n",data[i],data[j],ddata[k]);
			}
		}
	}
	return 0;
}