#include <iostream>
#include <utility>

#include <queue>

using namespace std;
typedef pair< long long ,long long > user;


priority_queue<user,vector<user> ,greater <user > >  pq;


int main(){


    pq.push(make_pair(1,2));

    int n=0;

    int data[1700];
    user t;
    while(n<1600){
        t=pq.top();
        pq.pop();


        switch(t.second){

        case 2:
            pq.push(make_pair(t.first*2,2));

        case 3:
            pq.push(make_pair(t.first*3,3));

        case 5:
            pq.push(make_pair(t.first*5,5));
        }
        //cout<<t.first<<endl;

        data[n++]=t.first;


    }


    int sum[1700]={0};

    for(int i=1;i<1600;i++){
        //cout<<data[i]<<endl;
        sum[i]=sum[i-1]+(data[i]-data[i-1]-1);
    }


    int T;
    cin>>T;

    while(T--){

        int n;
        cin>>n;

        int i=0;
        while(sum[i]<n)
            i++;

        cout<<i+n<<endl;
    }

}
