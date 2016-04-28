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

/*standard values*/

#define INF 1e18
#define PI 3.14159265359
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

ll a[1001][1001],ans[1001][1001];
bool vis[1001][1001];

/*Functions */


/*main code*/
int main(){
	FastIn;
	ll n,i,j,val,p;
	cin>>n;
	init(ans,1e15(ll`));
	init(vis,false);
	rep(i,0,n-1) rep(j,0,n-1)cin>>a[i][j];
	ans[0][0]=a[0][0];
	vis[0][0]=1;
	rep(i,0,n-1) rep(j,0,n-1) {
		if(i==0 && j==0)continue;
		val=1e12+1;
		if(i>0 && vis[i-1][j]==1)val=min(val,ans[i-1][j]);
		if(j>0 && vis[i][j-1])val=min(val,ans[i][j-1]);
		if(i<n-1 && vis[i+1][j])val=min(val,ans[i+1][j]);
		if(j<n-1 && vis[i][j+1])val=min(val,ans[i][j+1]);
		ans[i][j]=val+a[i][j];
		out4(i,j,val,a[i][j]);
		out1(ans[i][j]);
		vis[i][j]=1;
		if(i>0){

			ans[i-1][j]=min(a[i][j-1]+ans[i][j],ans[i-1][j]);
			out2(a[i][j-1]+ans[i][j],ans[i-1][j]);
		}
		if(j>0){
			ans[i][j-1]=min(a[i][j-1]+ans[i][j],ans[i][j-1]);
			out2(a[i][j-1]+ans[i][j],ans[i][j-1]);
		}
		if(i<n-1){
			ans[i+1][j]=min(a[i+1][j]+ans[i][j],ans[i+1][j]);
			out2(a[i+1][j]+ans[i][j],ans[i+1][j]);
		}
		if(j<n-1){
			out2(a[i][j+1]+ans[i][j],ans[i][j+1]);
			out2(a[i][j+1]+ans[i][j],ans[i][j+1]);
		}
	}
	cout<<endl;
	rep(i,0,n-1){
	rep(j,0,n-1)cout<<ans[i][j]<<" ";
	cout<<endl;
	}
	printf("%lld\n",ans[n-1][n-1]);
}
