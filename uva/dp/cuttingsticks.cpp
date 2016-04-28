/*Hemanth Kumar */

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

/*standard values*/

#define INF 1e18
#define PI 3.14
#define MAX 1000006

/*Frequent functions*/

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar


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

int dp[52][52];
VI a;

int func(int start,int end){
	if(end-start==1) return 0;
	if(dp[start][end]!=-1) return dp[start][end];
	int i,ans=1e7+1;
	rep(i,start+1,end-1)ans=min(ans,a[end]-a[start]+func(start,i)+func(i,end));
	dp[start][end]=ans;
	return ans;
}

/*main code*/
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l;
	while(1){
		cin>>l;
		if(l==0)break;
		int n,i,x;
		cin>>n;
		a.clear();
		a.PB(0);
		init(dp,-1);
		rep(i,1,n){
			cin>>x;
			a.PB(x);
		}
		a.PB(l);
		cout<<"The minimum cutting is "<<func(0,n+1)<<".\n";
	}
	return 0;
}
