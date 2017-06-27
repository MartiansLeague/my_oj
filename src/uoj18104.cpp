#include <cstdio>


int gcd(int a,int b){

    if(a<b){
        int temp=a;
        a=b;
        b=temp;
    }
    int r;
    r=a%b;
    while(r>=1){
        a=b;
        b=r;
        r=a%b;
    }

    return b;

}

int fn(long long a,long long b){

    long long  r =gcd(a,b);
    printf("%lld\n",a/r*b);
}

int main(){

    int n;
    int a,b;
    scanf("%d",&n);
    while(n--){


        scanf("%d%d",&a,&b);
        fn(a,b);
    }
    printf("group 1 done\n");
    while(scanf("%d%d",&a,&b) &&a){
        fn(a,b);
    }
printf("group 2 done\n");
    while(scanf("%d%d",&a,&b)>0){
        fn(a,b);
    }
    printf("group 3 done\n");
    return 0;
}
