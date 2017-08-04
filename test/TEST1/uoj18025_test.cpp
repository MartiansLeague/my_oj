#include <cstdio>



int n,m,store[33],p[50]= {0},ans=0;



void f(int t)
{

    if(t>n)
    {
        ans++;
        return ;
    }

    int i,sum=0;
    for(i=t-1;i>t-m && i>0;i--){
        sum+=store[i];
    }

    for(i=0;i<=9;i++){


        if(p[sum+i]||t<m){
            store[t]=i;
            f(t+1);
        }
    }
}



int main(){


    int t;

    scanf("%d",&t);


    p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=p[37]=1;

    while(t--){
        ans=0;
        scanf("%d%d",&n,&m);
        f(1);

        printf("%d\n",ans);
    }
    return 0;
}
