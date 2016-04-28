#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define mod 1000000007
using namespace std;
long long a[1003]={0},dp[1003]={0};
int main()
{
	long long int i,j,n,ans=0,l;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=0;
	}
	for(i=1;i<=n;i++) dp[i+1]=(2*dp[i]-dp[a[i]]+2)%mod;//because he has to revisit the ith block twice to go to i+1 that second visit is from a[i]. so dp[i+1]=dp[i]+1(first)+dp[i]-dp[p[i]]+1(second ).

	cout<<(dp[n+1]+mod)%mod<<endl;
}
