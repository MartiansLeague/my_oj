#include <cstdio>


int gcd(int a,int b){

	int r;
	if(a<b){
		int t=a;
		a=b;
		b=t;
	}
	r=a%b;
	while(r>=1){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}


int sovle(int a,int b){

	long long  t=gcd(a,b);

	printf("%lld\n",(long long )a/t*b);
}



int main(){

	int T;
	scanf("%d",&T);
	int a,b;
	while(T--){

		scanf("%d%d",&a,&b);
		sovle(a,b);
	}

    printf("group 1 done\n");

	while(scanf("%d%d",&a,&b)&&a!=0){
		sovle(a,b);
	}

	while(scanf("%d%d",&a,&b)>0){
		sovle(a,b);
	}
}
