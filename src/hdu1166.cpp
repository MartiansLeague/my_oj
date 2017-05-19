/*线段树经典题*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <list>
#include <bitset>

using namespace std;

#define ll long long 
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1

typedef pair<int, int>pii;
typedef pair<ll, ll>pll;
typedef pair<double, double>pdd;

const double eps = 1e-6;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const double FINF = 1e18;

#define x first
#define y second

#define REP(i,j,k) for(int i =(j);i<=(k);i++)
#define REPD(i,j,k) for(int i =(j);i>=(k);i--)
#define print(x) cout<<(x)<<endl;
#define IOS ios::sync_with_stdio(0);cin.tie(0);


#define M 50005  
int sum[M<<2];  //节点
int l,r,mid,id;
inline void PushPlus(int id)  
{  
    sum[id] = sum[(lson)] + sum[(rson)];  
}  
  
void Build(int l, int r, int id)  
{  
    if(l == r)  
    {  
        scanf("%d", &sum[id]);//根节点  
        return ;  
    }  
    int mid = ( l + r )>>1;  
  
    Build(lson);  
    Build(rson);  
    PushPlus(id);  
}  
  
void Updata(int p, int add, int l, int r, int id)  
{  
  
    if( l == r )  
    {  
        sum[id] += add;  
        return ;  
    }  
    int mid = ( l + r ) >> 1;  
    if(p <= mid)  
        Updata(p, add, lson);  
    else  
        Updata(p, add, rson);  
  
    PushPlus(id);  
}  
  
int Query(int L,int R,int l,int r,int id)  
{  
    if( L <= l && r <= R )  
    {  
        return sum[id];  
    }  
    int mid = ( l + r ) >> 1;  
    int ans=0;  
    if(L<=mid )  
        ans+=Query(L,R,lson);  
    if(R>mid)  
        ans+=Query(L,R,rson);  
  
    return ans;  
}  


int n, a, b;

void Init(){
	scanf("%d",&n);  
    Build(1,n,1);  
	return ;
}

void Solve(int T){
	printf("Case %d:\n",T); 

	char op[10];  
	while( scanf("%s",op) &&op[0]!='E' )  
        {  
  
            scanf("%d %d", &a, &b);  
            if(op[0] == 'Q')  
                printf("%d\n",Query(a,b,1,n,1));  
            else if(op[0] == 'S')  
                Updata(a,-b,1,n,1);  
            else  
                Updata(a,b,1,n,1);  
  
        }
	return ;
}

int main(){
#ifdef LOCAL
	freopen("hdu1166.in","r",stdin);
#endif
	int T;
	scanf("%d",&T); 
	REP(i,1,T)
	Init(),Solve(i);
	return 0;
}