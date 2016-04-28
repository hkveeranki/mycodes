#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int dp[1025][1025];
struct info{
	int x;
	int y;
	int size;
};
info rats[20004];
int main()
{
	int t;cin>>t;
	while(t--){
		int n,d,i,j,k,X,Y,Z,ans=-1,ansx=-1,ansy=-1;
		cin>>d>>n;
		for(i=0;i<1024;i++)for(j=0;j<1024;j++)dp[i][j]=0;
		for(i=0;i<n;i++)cin>>rats[i].x>>rats[i].y>>rats[i].size;
		for(i=0;i<n;i++){
			X=rats[i].x;
			Y=rats[i].y;
			Z=rats[i].size;
			for(j=X-d;j<=X+d;j++){
				if(j<0||j>=1024) continue;
				for(k=Y-d;k<=Y+d;k++){
					if(k<0||k>=1024) continue;
					dp[j][k]+=Z;
				}
			}
		}
		for(i=0;i<1024;i++)
			for(j=0;j<1024;j++)
				if(dp[i][j] >ans){
					ans=dp[i][j];
					ansx=i;ansy=j;
				}
		cout<<ansx<<" "<<ansy<<" "<<ans<<endl;
	}
}
