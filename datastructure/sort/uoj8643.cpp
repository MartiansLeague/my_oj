#include <iostream>

using namespace std;


void print(int *nums,int len){
    for(int i=1;i<=len;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
}

void ShellInsert(int * nums,int len,int dk){
    int temp;
    for(int i=dk+1;i<=len;++i){
        if(nums[i]<nums[i-dk]){
            temp=nums[i];
            int j;
            for(j=i-dk;j>0&&temp<nums[j];j-=dk)
                nums[j+dk]=nums[j];
            nums[j+dk]=temp;
        }
    }
}

void ShellSort(int *nums,int len,int delta[],int t){

    for(int k=0;k<t;k++){
        ShellInsert(nums,len,delta[k]);
        print(nums,len);
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

    ShellSort(nums,n,D,cur-1);
    return 0;

}
