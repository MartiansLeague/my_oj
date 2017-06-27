#include <iostream>

#include <algorithm>
using namespace std;

int dp[55][2005];

int main(){

    int n;
    cin>>n;

    int h[300],l[300];

    for(int i=0;i<n;i++){
        cin>>h[i+1];
    }

    for(int i=1;i<=n;i++){
        cin>>l[i];
    }


    int maxp=1999;

    for(int i=0;i<=maxp;i++){

        if(i>=l[1]){
            dp[1][i]=h[1];
        }
        else{
            dp[1][i]=0;
        }
    }

    for(int i=2;i<=n;i++){

        for(int j=0;i<=maxp;j++){

            if(j>=l[i]){

                dp[i][j]=max(dp[i-1][j],dp[i-1][j-l[i]]+h[i]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[n][maxp]<<endl;
}
