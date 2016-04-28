#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<set>
#define MAX 1000006
#define INF 100000000
using namespace std;
typedef long long int ll;
struct edge{
	ll v;
	ll w;
	ll number;
};
vector<edge> lis[MAX];
ll parweight[MAX];
ll dis[MAX];
ll edgenum[MAX];
ll n;
void djik(ll src){
	for(ll i=0;i<=n;i++)dis[i]=INF;
	dis[src]=0;
	set<pair<ll,ll> >q;
	q.insert(make_pair(0,src));
	pair<ll,ll> cur;
	while(!q.empty()){
		cur=*q.begin();
		q.erase(q.begin());
		ll tmp=cur.second;
		for(ll i=0;i<lis[tmp].size();i++){
			if(dis[lis[tmp][i].v]>dis[tmp]+lis[tmp][i].w){
				if(dis[lis[tmp][i].v]!=INF)
					q.erase(q.find(make_pair(dis[lis[tmp][i].v],lis[tmp][i].v)));
				parweight[lis[tmp][i].v]=lis[tmp][i].w;
				edgenum[lis[tmp][i].v]=lis[tmp][i].number;
				dis[lis[tmp][i].v]=dis[tmp]+lis[tmp][i].w;
				q.insert(make_pair(dis[lis[tmp][i].v],lis[tmp][i].v));
			}
			if (dis[lis[tmp][i].v]==dis[tmp]+lis[tmp][i].w){
				if(parweight[lis[tmp][i].v]>lis[tmp][i].w)
				{
					parweight[lis[tmp][i].v]=lis[tmp][i].w;
					edgenum[lis[tmp][i].v]=lis[tmp][i].number;
				}
			}
		}
	}
}
int main()
{
	ll m,i,ans=0,x,y,w;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		edge tmp1,tmp2;
		cin>>x>>y>>w;
		tmp1.v=x;
		tmp1.number=tmp2.number=i;
		tmp2.v=y;
		tmp1.w=tmp2.w=w;
		lis[x].push_back(tmp2);
		lis[y].push_back(tmp1);
	}
	cin>>x;
	djik(x);
	for(i=1;i<=n;i++)if(i!=x)ans+=parweight[i];
	cout<<ans<<endl;
	for(i=1;i<=n;i++)if(i!=x)cout<<edgenum[i]<<" ";
	cout<<endl;
}
