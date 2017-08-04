#include <iostream>
#include <algorithm>


using namespace std;






int dp[55][2005]={0};
int main(){



    int n;
    cin>>n;
    int h[n];
    int l[n];


    int m=1999;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }

    for(int i=1;i<=m;i++){
        if(i>l[1]){
            dp[1][i]=h[1];
        }
        else{
            dp[1][i]=0;
        }

    }


    for(int i=2;i<=n;i++){
        for (int j=0;j<=m;j++){
            if(j>=l[i])
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-l[i]]+h[i]);
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[n][m]+1<<endl;





    return 0;

}
