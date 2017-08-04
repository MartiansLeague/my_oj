



#include<cstdio>

typedef long long l;

l f(l a){
    if(a<=1) return 1;
    return f(a-1)*a;
}

l s( int a,int b){


    if( 2*a -1 <b) return 0;


    if( a>1)
        if(b>1)
            return s(a-1,b)+s(a-1,b-1)+s(a-1,b-2);
        else if(b==1)
            return s(a-1,b)+s(a-1,b-1);
        else return 1;

    if(a==1){

        if(b>1) return 0;
        else{
            return 1;
        }
    }
}


int main(){

    int t;
    scanf("%d",&t);
    while(t--){


        int a,b;
        scanf("%d%d",&a,&b);
        l res;
        if(a==0) res=0;
        else if(b==0) res=f(a);
        else res=f(a)*f(b)*(s(a,b)+s(a,b-1));

        printf("%lld\n",res);
    }
}
