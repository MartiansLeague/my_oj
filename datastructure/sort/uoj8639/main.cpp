#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<int > data;

void print(){
    for(vector<int>::iterator  it=data.begin();it!=data.end();it++)
             cout<<*it<<' ';
    cout<<endl;

}
void sort(){
    for(vector<int>::iterator  it=data.begin();it!=data.end();it++){
        for(vector<int>::iterator  i=data.begin();i!=it;i++){
            if(*i>*it){
                data.insert(i,*it);
                data.erase(it+1);
            }

        }

        if(it!=data.begin()) print();
    }
}
int main(){

    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        data.push_back(num);
    }
    if(data.size()==1){
        print();
    }else{
        if(data.size()==2){
            if(data[0]>data[1]){
                cout<<data[1]<<' '<<data[0]<<endl;
            }else{
                print();
            }
        }else{
            sort();
        }

    }

    return 0;
}
