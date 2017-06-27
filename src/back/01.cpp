#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
void method_two()
{
    int space;
    int n;
    int i,j;
    printf("请输入背包的容量（所装物品的最大质量和）：\n");
    scanf("%d",&space);
    printf("请输入物品的个数：\n");
    scanf("%d",&n);
    int v[n+1];//价值
    int w[n+1];//容量
    int f[n+1][space+1];

       memset(v,0,sizeof(v));
    memset(w,0,sizeof(w));
    memset(f,0,sizeof(f));

    printf("请依次输入物品的价值\n");
    for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
    printf("请依次输入物品的重量\n");
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);



    for(i=1;i<=n;i++)//逐个物品放入背包
    {
        for(j=0;j<=space;j++)//假定背包不同容量的情况。同时，因为i的限制，f[i][j]的值是和上一个f[i][j]相关，故j循环次序不受限制
        {
            f[i][j]=(i==1?0:f[i-1][j]);//i=n是边界条件，f[i-1][j]是上一次得出的结果
            if(j>=w[i])f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);//f[i][j]在上一条式子中已经被赋值为f[i+1][j]的值


        }
    }
    for(i=0;i<=n;i++)//逐个物品放入背包
    {
        for(j=space;j>=0;j--)//假定背包不同容量的情况。同时，因为i的限制，f[i][j]的值是和上一个f[i][j]相关，故j循环次序不受限制
        {
        printf("%d ",f[i][j]);
    }
    printf("\n");

}




}


int main(){

    method_two();
}
