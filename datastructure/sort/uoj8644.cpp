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


void fit(int * num,int s,int end){

    int t=num[s];

    for(int j = 2* s;j<=end;j*=2){

        if(j<end && num[j]<num[j+1]){
            j++;
        }

        if(t>=num[j]){
            break;
        }

        num[s]=num[j];
        s=j;

    }
    num[s]=t;
}
void HeapSort(int * num,int len){

    for(int i =len/2; i>0;i--){

        fit(num,i,len);
    }
    print(num,len);
    for(int i=len;i>1;--i){
        swap(num[1],num[i]);
        fit(num,1,i-1);
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

    HeapSort(nums,n);
    return 0;

}
