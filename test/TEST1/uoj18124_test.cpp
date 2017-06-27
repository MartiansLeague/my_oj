#include <iostream>
#include <cstring>

using namespace std;

int n,ans,d[2][200],r[200];


void dfs(int cur){

    if(cur==n+1){
        ans++;
        return ;
    }


    for(int i=1;i<=n;i++){


        if( !r[i] && ! d[0][cur+i] && ! d[1][cur -i+n]){

            r[i]=d[0][cur+i]=d[1][cur -i+n]=1;
            dfs(cur+1);
            r[i]=d[0][cur+i]=d[1][cur -i+n]=0;


        }
    }
}

int main(){

    int t;
    cin>>t;

    while(t--){
        ans=0;
        memset(d,0,sizeof(d));
        memset(r,0,sizeof(r));

        cin>>n;
        dfs(1);

        cout<<ans<<endl;



    }
}
