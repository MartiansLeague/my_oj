/*

18105 银行的叫号顺序
时间限制:8000MS  内存限制:65535K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC
Description
银行的叫号过程是一个优先队列的典型应用，假设，银行有4类客户，分别用优先级1，2，3，4表示，级别越高
则更优先得到服务，例如，当前有三个人排队，两个1级客户，一个3级客户，则银行叫号时，3级客户将先得到服务
，即使另两个1级有客户比他先到。当多个同级的客户将获得服务时，由先到的客户先得到服务。

假设，银行只有一个服务窗口，一次只能服务一个客户，假设该窗口每5分钟服务一个客户，即叫号的时刻分别
为0分钟、5分钟、10分钟、.....如果在叫号的时侯，没有客户，银行职员会去喝杯咖啡或上个洗手间，5分钟后
再继续叫号。

银行给出一系列客户到来的记录，每条记录包括“客户到来的时”，“客户等级”，“客户姓名”（由一个单词构成），请输
出银行服务的客户的顺序。




输入格式
第一数字是客户的数量n（n<=100000）
此后，每一行是一个客户来访信息，包括3个数字，到来的时刻（分钟整点,最大10的8次方）、等级、姓名（最多20个字母）
（已经按到来时刻排序）


输出格式
按服务的先后顺序输出客户的姓名


输入样例
4
0 1 John
3 1 Smith
3 1 Tom
4 2 Flod


输出样例
John
Flod
Smith
Tom

*/

//下面是模板，不用看，都一样；
//****************************************
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
//*****模板结束************************


typedef  pair<int,string> user;// 客户
priority_queue<user > pq;		//客户的优先队列

int usernum;

void Init(){
	scanf("%d",&usernum);
	return ;
}

void Solve(){

	int ttime,lv;
	string name;

	int p=0;//时间 （%5）
	int ttweight=99999;//先后的权值

	while(usernum--){
        cin>>ttime>>lv>>name;//最好不要用cin，这题差一点就超时2333333333

        while(ttime-p>0){
        	//找出能被叫号的弹出来
        	//也就是时间满足条件的
            if(!pq.empty()){
                print(pq.top().y);
                pq.pop();
            }
            p+=5;
        }

        //重点！！！！！
        //pair的第一个数字当做优先队列的排序条件
        //加上一个权值，满足先来后到的条件
        pq.push(make_pair(lv*100000+ttweight,name));
        //所以等级lv高的，先来的会被排在优先队列的前面，一个一个按顺序弹出来就行


        ttweight--;
    }

    //看有没有剩下的，全部弹出
    while(!pq.empty()){
        print(pq.top().y);
        pq.pop();
    }

	return ;
}

/*还是模板*/
int main(){

	/*这个不用管，你要在编译器加上-DLOCAL 才会从文件读入，所以本地可以直接从文件读入，到oj上就不会了*/
#ifdef LOCAL
	//freopen("uoj18105.in","r",stdin);
#endif


	Init(),Solve();
	return 0;
}
