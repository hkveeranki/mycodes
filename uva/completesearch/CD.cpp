#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool isthere[21];
vector<int>ans;
int len[21],n,m,minm;
void solve(int u,int sum){
	//cout<<"Sum= "<<sum<<" u= "<<u-1<<" "<<isthere[u-1]<<endl;
	if(sum>n)return ;
	if(n-sum>=0 && n-sum<minm){
		ans.clear();
		minm=n-sum;
		//cout<<"len[i] is\n";
		for(int i=0;i<m;i++)
			if(isthere[i]==1){
				//cout<<len[i]<<" ";
				ans.push_back(len[i]);
			}
		//cout<<endl;
	}
	if(u>=m)return ;
	sum+=len[u];
	isthere[u]=1;
	solve(u+1,sum);
	sum-=len[u];
	isthere[u]=0;
	solve(u+1,sum);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j,k;
		for(i=0;i<m;i++)cin>>len[i];
		for(i=0;i<m;i++)isthere[i]=0;
		minm=n;
		solve(0,0);
		for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";
		cout<<"sum:"<<n-minm<<endl;
	}
	return 0;
}
