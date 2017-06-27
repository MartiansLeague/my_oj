#include<cstdio>
#include <iostream>
#include <algorithm>
using namespace std;



typedef struct {
    int s;
    int m;
    char name[30];
} user;


int cmp(user a,user b){

    if(a.s==b.s){

        return a.m<b.m;

    }
    return a.s>b.s;
}
user data[1000000];
int main(){



    int n;

    cin>>n;



    for(int i=0;i<n;i++){

        scanf("%d%d%s",&data[i].s,&data[i].m,data[i].name);

    }

    stable_sort(data,data+n,cmp);

    for(int i=0;i<n;i++){
        printf("%s\n",data[i].name);
    }
}
