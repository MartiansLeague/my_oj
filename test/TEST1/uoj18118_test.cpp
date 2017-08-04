#include <cstdio>
#include <algorithm>

using namespace std;
int data[200010],user[200010];

int main(){


    int n,m;

    while(scanf("%d%d",&n,&m)&& n>0 &&m>0){
        for(int i=0;i<n;i++){
            scanf("%d",data+i);
        }

        for(int i=0;i<m;i++){
            scanf("%d",user+i);
        }

        sort(data,data+n);
        sort(user,user+m);

        int i,j;
        i=j=0;

        int sum=0;


        while(i<n&&j<m){
            if(data[i]<=user[j]){
                sum+=user[j];
                i++;
                j++;
            }else{
                j++;
            }

        }

        if(i!=n){
            printf("Loowater is doomed!\n");
        }else{
            printf("%d\n",sum);
        }


    }
    return 0;
}
