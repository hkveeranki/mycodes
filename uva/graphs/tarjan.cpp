/*Hemanth Kumar */

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

/*standard values*/

#define INF 1e18
#define PI 3.14159265359
#define MAX 1000006

/*Frequent functions*/

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar


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
#define WHITE 0
#define BLACK 1

VI lis[MAX];
VI inp[MAX];
int rank[MAX],parent[MAX],ansector[MAX];
bool color[MAX];

/*Functions */
void makeset(int u){
	parent[u]=u;
	rank[u]=0;
}
int Find(int x){
	if(parent[x]!=x)parent[x]=Find(parent[x]);
	return parent[x];
}
void uni(int x,int y){
	int rx=Find(x);
	int ry=Find(y);
	if(rank[rx]>rank[ry])parent[ry]=rx;
	else if (rank[rx]<rank[ry])parent[rx]=ry;
	else {
		parent[ry]=rx;
		rank[rx]++;
	}
}
bool vis[200005];
void dfs(int u){
	vis[u]=1;
	cout<<u<<"\n";
	for(int i=0;i<lis[u].size();i++)if(!vis[lis[u][i]])dfs(lis[u][i]);
}
void tarjan(int u){
	makeset(u);
	ansector[u]=u;
	int i,n,v;
	n=lis[u].size();
	rep(i,0,n-1){
		v=lis[u][i];
		tarjan(v);
		uni(u,v);
		ansector[Find(u)]=u;
	}
	color[u]=BLACK;
	n=inp[u].size()-1;
	rep(i,0,n){
		v=inp[u][i];
		if(color[v]==BLACK){
			printf("Tarjan's Lowest Common Ancestor of %d and %d is %d.\n",u,v,ansector[Find(v)]);
		}
	}
}
/*main code*/
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i,x,n,y,q;
	cin>>n>>q;
	init(vis,false);
	rep(i,1,n)color[i]=WHITE;
	rep(i,2,n){
		cin>>x;
		lis[x].PB(i);
	}
	rep(i,1,q){
		cin>>x>>y;
		inp[x].PB(y);
		inp[y].PB(x);
	}
	cout<<"the graph is :\n";
	dfs(1);
	//tarjan(1);
	return 0;
}
