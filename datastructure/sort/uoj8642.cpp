#include <iostream>

using namespace std;


void print(int *nums,int len){
    for(int i=1;i<=len;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
}

void swap(int&a,int &b){
    int temp;

    temp=a;
    a=b;
    b=temp;
}

int len;
int patch(int *num,int start,int end){

    int temp=num[start];
    while(start<end){
        while(start<end && num[end]>=temp) end--;
        num[start]=num[end];

        while(start<end && num[start]<=temp) start++;
        num[end]=num[start];
    }

    num[start]=temp;
    print(num,len);
    return start;

}
void qsort(int *nums,int s,int e){

    if(s<e){
        int p=patch(nums,s,e);
        qsort(nums,s,p-1);
        qsort(nums,p+1,e);
    }

}


int main(){
    int n;
    cin >>n;
    len=n;
    int i;
    int nums[n+2];
    for(i=1;i<=n;i++){
        cin>>nums[i];
    }
    if(n==1){
        cout<<nums[1]<<endl;
        return 0;
    }

    qsort(nums,1,n);

    return 0;

}
