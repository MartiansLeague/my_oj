#include <queue>
#include <iostream>
#include <utility>
#include <cstdio>
using namespace std;

typedef pair<int,int > user;

int main()
{

    int n,nn;

    cin>>n;

    nn=n;
    queue<user> users;

    while(n--)
    {
        int intime,outt;
        cin>>intime>>outt;
        users.push(make_pair(intime,outt));
    }

    int now=0;
    int sum=0;

    while(!users.empty())
    {
        switch(now>=users.front().first)
        {
        case true:
            sum+=(now-users.front().first);
            now+=users.front().second;
            users.pop();
            break;
        case false:
            now=users.front().first;
        }
    }
    printf("%.2f",(float) sum/(float)nn);

}
