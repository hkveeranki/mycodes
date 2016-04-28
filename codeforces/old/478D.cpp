#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define mod 1000000007
using namespace std;
int dp[1000006];
void solve(int r,int b){
	int i,j,k,h,ans=0;
	dp[0]=dp[1]=1;
	if(r>b){
		r=r+b;
		b=r-b;
		r=r-b;
	}
	for(i=1;i<=1000;i++) if((i*(i+1))/2>(r+b)){h=i-1;break;} //max possible height with given bricks if they are proper :D
	for(i=2;i<=h;i++)
		for(j=r;j>=0;j--){
			k=(i*(i+1))/2-j;//supposed b if rows=r for a given height; here we know r,g are interchangeable in dp if values agree
			int tmp=0;
			if(j>=i)tmp=(tmp+dp[j-i])%mod;
			if(k>=i)tmp=(tmp+dp[j])%mod;//because same can be performed with r as b and b as r :P
			dp[j]=tmp;
		}
	int lim=(h*(h+1))/2;
	for(i=r;i>=0&& lim-i<=b;i--)ans=(ans+dp[i])%mod;//Why? because for a given h dp[r] assumes h-1 is built 1 level is built by red (as well as green)
	cout<<ans%mod<<endl;
}
int main()
{
	int r,b;
	cin>>r>>b;
	solve(r,b);
	return 0;
}
