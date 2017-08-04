#include <iostream>

using namespace std;



void swap(int & a,int &b){

    int temp;
    temp=a;
    a=b;
    b=temp;
}
void print(int *nums,int len){
    for(int i=1;i<=len;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
}

int min(int *num,int  s ,int e){

    int p=s;

    int mi=num[s];

    for (int i=s+1;i<=e;i++){

        if(num[i]<mi){
            p=i;
            mi=num[i];
        }
    }
    return p;

}
void SelectSort(int * num,int len){

    for(int i=1;i<len;++i){
        int pos=min(num,i,len);
        swap(num[i],num[pos]);
    print(num,len);
    }

}
int main(){
    int n;
    cin >>n;

    int i;
    int nums[n+2];
    for(i=1;i<=n;i++){
        cin>>nums[i];
    }
    if(n==1){
        cout<<nums[1]<<endl;
        return 0;
    }

    int D[n];
    int l=n;
    int cur=0;
    while(l>=1){
        D[cur++]=l/2;
        l=l/2;
    }

    SelectSort(nums,n);
    return 0;

}
