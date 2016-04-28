#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int rank[100005],parent[100005];
int find(int i){
	if(parent[i]!=i)parent[i]=find(parent[i]);
	return parent[i];
}
void setu(int i,int j){
	int pi=find(i);
	int pj=find(j);
	if(rank[pi]>rank[pj]) parent[pj]=pi;
	else if(rank[pj]>rank[pi])parent[pi]=pj;
	else{
		parent[pj]=pi;
		rank[pi]++;
	}
}
int main()
{
	int n,m,i,x,y,ans,count=0;
	cin>>n>>m;
	while(!(n==0 && m==0)){
		count++;
		for(i=1;i<=n;i++){
			parent[i]=i;
			rank[i]=0;
		}
		for(i=1;i<=m;i++){
			cin>>x>>y;
			if(find(x)!=find(y))setu(x,y);
		}
		for(i=1,ans=0;i<=n;i++)if(parent[i]==i)ans++;
		cout<<"Case "<<count<<": "<<ans<<endl;
		cin>>n>>m;
	}
}
