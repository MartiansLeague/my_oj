#include <cstdio>
#include <cmath>


int sovle(int n){

    int a=n*n;

    for(int i=2502;i>=3;i--){
        int b=i*i;

        int k1=sqrt(a+b);
        if(k1*k1==a+b&&k1>0&&i>=k1){
            printf("%d,%d\n",i,k1);
        }

        k1=sqrt(a-b);
        if(k1*k1==a-b&&k1>0&&i>=k1){
            printf("%d,%d\n",i,k1);
        }

        k1=sqrt(b-a);
        if(k1*k1==b-a&&k1>0&&i>=k1){
            printf("%d,%d\n",i,k1);
        }
    }


}

int main(){

    int n;
    scanf("%d",&n);

    while(n--){
        int t;
        scanf("%d",&t);
        sovle(t);
        printf("\n");
    }

}
