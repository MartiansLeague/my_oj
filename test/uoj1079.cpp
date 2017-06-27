#include <cstdio>
#include <cmath>




int sovle( int n){


    int a=n*n;

    for( int i=2501;i>=3;i--){

        int b=i*i;

        int k=sqrt(a+b);


        if(k*k ==a+b && k>0 && i>=k ){
            printf("%d,%d\n" ,i,k);
        }

         k=sqrt(a-b);


        if(k*k ==a-b && k>0 && i>=k ){
            printf("%d,%d\n" ,i,k);
        }

         k=sqrt(b-a);
        if(k*k ==b-a && k>0 && i>=k ){
            printf("%d,%d\n" ,i,k);
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
