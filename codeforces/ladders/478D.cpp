/*Author: Hemanth Kumar Veeranki */

/*handle: harry7*/

/*header files*/

#include<bits/stdc++.h>

using namespace std;

/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
/*standard values*/

#define INF 1e18
#define PI 3.14159265359

/*Frequent functions*/

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar
#define FastIn std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)

/*typedef's for frequently used*/

typedef long long int ll;
typedef vector<int>VI;
typedef vector<ll>VLI;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
typedef unsigned long long int ull;

/*space for global variables*/

#define mod 1000000007
int dp[1000006];

/*Functions */

void solve(int r,int b){
	int i,j,k,h,ans=0;
	dp[0]=dp[1]=1;
	if(r>b){
		r=r+b;
		b=r-b;
		r=r-b;
	}
	rep(i,1,1000) if((i*(i+1))/2>(r+b)){h=i-1;break;} //max possible height with given bricks if they are proper :D
	rep(i,2,h)
		repi(j,r,0){
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


/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int r,b;
	cin>>r>>b;
	solve(r,b);
	//exectime();
	return 0;
}
