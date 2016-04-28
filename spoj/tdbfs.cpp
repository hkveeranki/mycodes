/*Author: Hemanth Kumar Veeranki */

/*handle: harry7*/

/*header files*/

#include<bits/stdc++.h>

using namespace std;

/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
/*standard values*/

#define INF 1e18
#define PI 3.14159265359

/*Frequent functions*/

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar
#define FastIn std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)

/*typedef's for frequently used*/

typedef long long int ll;
typedef vector<int>VI;
typedef vector<ll>VLI;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
typedef unsigned long long int ull;

/*space for global variables*/

#define MAX 1001
VI a[MAX];
queue<int>q;
bool vis[MAX];

/*Functions */

void dfs(int src){
	vis[src]=1;
	cout<<src<<" ";
	for(int i=0;i<a[src].size();i++) if(!vis[a[src][i]])dfs(a[src][i]);
}
void bfs(int src){
	int i,j;
	vis[src]=1;
	q.push(src);
	while(!q.empty()){
		src=q.front();
		q.pop();
		cout<<src<<" ";
		rep(i,0,(int)a[src].size()-1) if(!vis[a[src][i]]){
			vis[a[src][i]]=1;
			q.push(a[src][i]);
		}
	}
}

/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	ll cnt=0;
	TC(){
		cnt++;
		int n,m,i,j,x,y;
		cin>>n;
		n;
		rep(i,1,n){
			cin>>x>>m;
			rep(j,1,m){
				cin>>y;
				a[x].PB(y);
			}
		}
		cout<<"graph "<<cnt<<"\n";
		cin>>x>>y;
		while(x!=0){
			init(vis,false);
			if(y==0)dfs(x);
			else bfs(x);
			cout<<"\n";
			cin>>x>>y;
		}
	rep(i,1,n)if(a[i].size()>0)a[i].clear();
	}
	//exectime();
	return 0;
}
