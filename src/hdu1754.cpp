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


const int maxn = 222222;  
int MAX[maxn<<2];  


void PushUP(int id) {  
    MAX[id] = max(MAX[id<<1] , MAX[id<<1|1]);  
}  


void build(int l,int r,int id) {  
    if (l == r) {  
        scanf("%d",&MAX[id]);  
        return ;  
    }  
    int mid = (l + r) >> 1;  
    build(lson);  
    build(rson);  
    PushUP(id);  
}  
void update(int p,int sc,int l,int r,int id) {  
    if (l == r) {  
        MAX[id] = sc;  
        return ;  
    }  
    int mid = (l + r) >> 1;  
    if (p <= mid) update(p , sc , lson);  
    else update(p , sc , rson);  
    PushUP(id);  
}  
int query(int L,int R,int l,int r,int id) {  
    if (L <= l && r <= R) {  
        return MAX[id];  
    }  
    int mid = (l + r) >> 1;  
    int ret = 0;  
    if (L <= mid) ret = max(ret , query(L , R , lson));  
    if (R > mid) ret = max(ret , query(L , R , rson));  
    return ret;  
}  
int n , m; 


void Init(){

	build(1 , n , 1); 
	return ;
}

void Solve(){
	
	while (m --) {  
            char op[2];  
            int a , b;  
            scanf("%s%d%d",op,&a,&b);  
            if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));  
            else update(a , b , 1 , n , 1);  
    }  
	return ;
}

int main(){
#ifdef LOCAL
	freopen("hdu1754.in","r",stdin);
#endif

	while (~scanf("%d%d",&n,&m))
	Init(),Solve();
	return 0;
}  