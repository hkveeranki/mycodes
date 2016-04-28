#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define MAX 502
using namespace std;
int a[MAX],dp[MAX][MAX]={0};
int main()
{
	long long int n,m,b,i,j,mod,ans,k;
	cin>>n>>m>>b>>mod;
	dp[0][0]=1;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(k=a[i];k<=b;k++){
				dp[j][k]+=dp[j-1][k-a[i]];//because m,r bugs will be m-1 and r-1 r-2 ... got it??;		
				if(dp[j][k]>=mod)dp[j][k]%=mod;
			}
	ans=0;
	for(i=0;i<=b;i++){
		ans+=dp[m][i];
		if(ans>=mod)ans%=mod;
	}
	cout<<ans<<endl;
}
