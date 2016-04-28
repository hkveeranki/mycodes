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

#define MAX 100005
int time1,ans;
VI lis[MAX];
stack<int> st;
int low[MAX],disc[MAX];
bool onstack[MAX];

/*Functions */

void dfs(int u){
	low[u]=disc[u]=++time1;
	st.push(u);
	onstack[u]=true;
	int i,j,n,w;
	n=lis[u].size();
	rep(i,0,n-1){
		j=lis[u][i];
		if(disc[j]==-1){
			dfs(j);
			low[u]=min(low[j],low[u]);
		}
		else if(onstack[j])low[u]=min(disc[j],low[u]);
	}
	if(low[u]==disc[u]){
		ans++;
		while(st.top()!=u){
			w=st.top();
			onstack[w]=false;
			st.pop();
		}
		w=st.top();
		onstack[w]=false;
		st.pop();
	}
}

/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	TC(){
		int x,y,n,m,i;
		cin>>n>>m;
		init(low,-1);
		init(disc,-1);
		init(onstack,false);
		rep(i,1,m){
			cin>>x>>y;
			lis[x].PB(y);
		}
		ans=time1=0;
		rep(i,1,n){
			if(disc[i]==-1)dfs(i);
		}
		cout<<ans<<endl;
		rep(i,1,n){
			if(lis[i].size()>0)lis[i].clear();
		}
	}
	//exectime();
	return 0;
}
