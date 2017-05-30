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


int patch(int *nums,int end){
    int flag=0;
    for(int i=1;i<end;++i){

        if(nums[i]>nums[i+1]){
            swap(nums[i],nums[i+1]);
            flag=1;
        }

    }
    return flag;

}
void popsort(int *nums,int len){

    for(int i=len;i>=2;--i){
        if(patch(nums,i)){
            print(nums,len);
        }else{
            print(nums,len);
            return ;
        }

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

    popsort(nums,n);

    return 0;

}
