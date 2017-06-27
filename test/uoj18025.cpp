#include <iostream>
#include <algorithm>


using namespace std;

int ans;
int n,m;


int store[500];
int p[500]={0};


void dfs(int t){


    if(t>n){
        ans++;
        return ;

    }

    int sum=0;

    for(int i=t-1;i>t-m &&i>0;i--){

        sum+=store[i];
    }

    for(int i=0;i<=9;i++){

        if(p[sum+i]||t<m){
                store[t]=i;
            dfs(t+1);
        }
    }

}
int main(){

    p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=p[37]=1;

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ans=0;
        dfs(1);
        cout<<ans<<endl;

    }
}
