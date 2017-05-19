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



int p[50]={0};

void Init(){

	p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[23]=p[29]=p[31]=1;


	return ;
}

int a[30]={0};
int count1;
int m;
int add(int cur,int i){

	int sum=0;

	REP(j,0,m-2){
		sum+=a[cur-j];
	}
	sum+=i;
	if(p[sum]==1){
		return 1;
	}
	else{
		return 0;
	}

}
int n;

int dfs(int cur){
	REP(i,0,9){
		//print(i);
		if(add(cur,i)){
			print(i);
			if(cur==n+5){
				REP(j,0,20){
					cout<<a[i]<<" ";
				}
				cout<<endl;
				count1++;
			}else{
				a[cur++]=i;
				dfs(cur);
			}
			
		}
	}
}
void Solve(){
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	count1=0;
	dfs(6);
	cout<<count1<<endl;
	return ;
}

int main(){
#ifdef LOCAL
	freopen("uoj18025.in","r",stdin);
#endif

 	int t;
 	scanf("%d",&t);
 	while(t--)
	Init(),Solve();
	return 0;
}