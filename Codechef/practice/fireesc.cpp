#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
#define mod 1000000007
using namespace std;
long long rank[100005],parent[100005];
long long find(long long i){
	if(parent[i]!=i)parent[i]=find(parent[i]);
	return parent[i];
}
void setu(long long i,long long j){
	long long pi=find(i);
	long long pj=find(j);
	if(rank[pi]>rank[pj]) parent[pj]=pi;
	else if(rank[pj]>rank[pi])parent[pi]=pj;
	else{
		parent[pj]=pi;
		rank[pi]++;
	}
}
long long a[100005];
int main()
{
	long long n,m,i,x,y,ans=1,count=0,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		count=0;
		ans=1;
		for(i=1;i<=n;i++){
			parent[i]=i;
			a[i]=1;
			rank[i]=0;
		}
		for(i=1;i<=m;i++){
			cin>>x>>y;
			setu(x,y);
		}
		for(i=1;i<=n;i++)
			if(find(i)==i)count++;
			else a[parent[i]]++;
		for(i=1;i<=n;i++)if(parent[i]==i)ans=(ans*a[i])%mod;
		cout<<count<<" "<<ans<<endl;
	}
}
