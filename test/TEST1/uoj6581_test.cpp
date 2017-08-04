#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;

int data[105][105]={0};

int dp[105][105]={0};
int sovle(int a,int b){
    if(dp[a][b]>0){
        return dp[a][b];
    }
    if(a==n-1){
        return dp[a][b]=data[a][b];
    }

    if(b<=a){
        return dp[a][b]=max(sovle(a+1,b),sovle(a+1,b+1))+data[a][b];
    }

}


int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            scanf("%d",&data[i][j]);
        }
    }

    printf("%d\n",sovle(0,0));

}
