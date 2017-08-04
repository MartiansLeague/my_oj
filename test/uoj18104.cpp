#include <cstdio>

#include<iostream>


using namespace std;

typedef  long long ll;

ll gcd( ll a,ll b)
{


    if(a<b)
    {


        ll t=a;
        a=b;
        b=t;
    }


    ll r;

    r=a%b;

    while(r>=1)
    {
        a=b;
        b=r;

        r=a%b;
    }

    return b;

}


ll sovle(ll a,ll b)
{

    ll r=gcd(a,b);

    printf("%lld\n",a/r*b);

}



int main()
{


    int t;
    cin>>t;

    int a,b;
    while(t--)
    {
        cin>>a>>b;
        sovle(a,b);
    }

        printf("group 1 done\n");
    while(cin>>a>>b,a>0){

        sovle(a,b);

    }

printf("group 2 done\n");
    while(cin>>a>>b){

        sovle(a,b);
    }

printf("group 3 done\n");
    return 0;
}
