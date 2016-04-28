#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct info{
	int ta;
	int tl;
};
int main()
{
	int tc;
	cin>>tc;
	while(tc--){
		info ans[10004];
		queue<int>q[2];
		int i,j,actside,acttime,n,m1,t,p,m;
		cin>>n>>t>>m1;
		string s;
		for(i=0;i<m1;i++){
			cin>>p>>s;
			ans[i].ta=p;
			if(s[0]=='l')q[0].push(i);
			else q[1].push(i);
		}
		actside=0;
		acttime=0;
		while(!q[0].empty()||!q[1].empty())
		{
			if(q[0].empty()) m=ans[q[1].front()].ta;
			else if (q[1].empty())  m=ans[q[0].front()].ta;
			else m=min(ans[q[0].front()].ta,ans[q[1].front()].ta);
			//cout<<"m is "<<m<<endl;
			//cout<<"before : "<<acttime<<endl;
			acttime=max(m,acttime);
			//cout<<"After: "<<acttime<<endl;
			j=0;
			while(!q[actside].empty() &&ans[q[actside].front()].ta<=acttime && j<n){
				//cout<<"Entered with "<<acttime<<endl;
				ans[q[actside].front()].tl=acttime+t;
				j++;
				q[actside].pop();
			}
			acttime+=t;
			//cout<<acttime<<endl;
			actside=1-actside;
		}
		for(i=0;i<m1;i++)cout<<ans[i].tl<<endl;
		if(tc)cout<<endl;
	}
}
