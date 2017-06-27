#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int  main(){


    int n,m;

    cin>>n>>m;

    char  data[n+2][n+2];
    memset(data,0,sizeof(data));
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        data[a][b]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            printf("%d ",data[i][j]);
        }
        cout<<endl;
    }


    return 0;
}
