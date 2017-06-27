#include <cstdio>
#include <utility>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

typedef pair<long long,string> user;

priority_queue<user> pq;


int main()
{

    int n;
    cin>>n;
    int time,lv;
    string name;

    int now=0;
    int w=9999999;
    while(n--)
    {
        cin>>time>>lv>>name;
        while(now<time)
        {
            if(!pq.empty())
            {
                user u=pq.top();
                pq.pop();
                cout<<u.second<<endl;
            }
            now+=5;
        }

        pq.push(make_pair(lv*100000000+w,name));
        w--;
    }
    while(!pq.empty())
    {
        user u=pq.top();
        pq.pop();
        cout<<u.second<<endl;
    }


    return 0;
}
