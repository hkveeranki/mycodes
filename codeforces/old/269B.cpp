#include<iostream>
#define MAX 5005
using namespace std;
int type[MAX],dp[MAX];
int main()
{
	int n,m,ans=0,i,j;
	double pos;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>type[i]>>pos;
	for(i=1;i<=n;i++)
		for(j=type[i];j>=1;j--)
			dp[type[i]]=max(dp[type[i]],1+dp[j]);//wait why?? because we have to choose to max non deccreasing subsequence of length 
	for(i=1;i<=n;i++)ans=max(dp[i],ans);
	 cout<<(n-ans)<<endl;
}
