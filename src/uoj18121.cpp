
#include <cstdio>

using namespace std;

typedef long long  ll;


ll f(ll n)
{
    if(n==0) return 1;
    ll s = 1;
    for (ll i = 1; i <= n; i++)
        s = s * i;
    return s;
}


ll solve(ll n, ll w)
{
    if(2*n-1<w) return 0;

    if (n > 1)
    {
        if (w > 1)
            return solve(n - 1, w) + solve(n - 1, w - 1)+ solve(n - 1, w - 2);
        else if (w == 1)
            return  solve(n - 1, w - 1) + solve(n - 1, w);
        else if(w==0)
            return 1;
    }

    if (n == 1)
    {
        if(w==1)
            return 1;
        else if(w>1)
            return 0;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        ll n, w;
        scanf("%lld%lld", &n, &w);
        ll cases;

        if(n==0) cases=0;
        else if(w==0) cases=f(n);

        else cases = f(w)*f(n) * (solve(n, w)  + solve(n, w - 1));
        printf("%lld\n", cases);
    }
    return 0;
}
