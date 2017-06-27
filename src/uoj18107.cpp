#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;


struct user{
    int sroce;
    int min;
    char s[21];
};
user data[500002];

int cmp(user a,user b){
    if(a.sroce==b.sroce){
     return a.min<b.min;
    }
return a.sroce>b.sroce;
}
int main(){

    int T;
    scanf("%d",&T);

    int n=T;
    int i;
    for(i=0;i<n;i++){
        int a,b;
        scanf("%d%d%s",&a,&b,data[i].s);
        data[i].sroce=a;
        data[i].min=b;
    }
    stable_sort(data,data+n,cmp);
    for(i=0;i<n;i++){
        printf("%s\n",data[i].s);
    }
    return 0;
}
