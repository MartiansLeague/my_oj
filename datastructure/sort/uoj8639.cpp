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
    sort();
    return 0;
}
