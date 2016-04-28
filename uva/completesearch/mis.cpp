#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define BLACK 1
#define WHITE 0
using namespace std;
int maxm,n;
vector<int>ans;
vector< vector<int> >lis;
bool color[102],colored[102];
void solve(int u){
	if(u==n+1){
		int i,cnt=0;
		for(i=1;i<=n;i++)if(color[i]==BLACK)cnt++;
		if(cnt>maxm){
			maxm=cnt;
			ans.clear();
			for(i=1;i<=n;i++)if(color[i]==BLACK)ans.push_back(i);
		}
			return ; 
	}
	bool  flag=true;//shows whether it can be black  or not
	for(int i=0;i<lis[u].size();i++)
		if(colored[lis[u][i]] && color[lis[u][i]]==BLACK){
			flag=false;
			break;
		}
	colored[u]=1;
	if(flag){
		color[u]=BLACK;
		solve(u+1);
	}
	color[u]=WHITE;
	solve(u+1);
	colored[u]=0;

}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int m,i,j,x,y;
		cin>>n>>m;
		lis.assign(n+1,vector<int>());
		for(i=1;i<=m;i++){
			cin>>x>>y;
			lis[x].push_back(y);
			lis[y].push_back(x);
		}
		for(i=1;i<=n;i++)color[i]=colored[i]=0;
		maxm=-1;
		solve(1);
		cout<<maxm<<endl;
		for(i=0;i<ans.size();i++){
			cout<<ans[i];
			if(i!=ans.size()-1)cout<<" ";
		}
		cout<<endl;
		ans.clear();
	}
}
