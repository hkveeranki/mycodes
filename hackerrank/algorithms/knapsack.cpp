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

bool dp[2001][2001];
int wts[2001];

void solve(int n,int k){
	int i,j,m,ans=1e7+1;
	init(dp,false);
	for(j=0;j*wts[0]<=k;j++)dp[k-j*wts[0]][0]=1;
	for(i=1;i<n;i++){
		for(m=0;m<=k;m++)if(dp[m][i-1])
			for(j=0;j*wts[i]<=m;j++){
				dp[m-j*wts[i]][i]=1;
				//cout<<m-j*wts[i]<<" "<<i<<" "<<dp[m-j*wts[i]][i]<<endl;
			}
	}
	for(i=0;i<=k;i++)
		for(j=0;j<n;j++)if(dp[i][j]==1){
			//out2(i,j);
			ans=min(ans,i);
			//out1(ans);
		}
	cout<<k-ans<<endl;
}
/*main code*/
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	TC(){
		int n,i,k;
		cin>>n>>k;
		rep(i,0,n-1)cin>>wts[i];
		solve(n,k);
	}
	return 0;
}
