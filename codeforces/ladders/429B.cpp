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

#define MAX 1002
ll a[MAX][MAX],ans11[MAX][MAX],ans12[MAX][MAX],ans21[MAX][MAX],ans22[MAX][MAX];

/*Functions */


/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	ll m,n,i,j,ans=0;
	cin>>n>>m;
	rep(i,1,n)rep(j,1,m)cin>>a[i][j];
	rep(i,1,n)rep(j,1,m)ans11[i][j]=a[i][j]+max(ans11[i-1][j],ans11[i][j-1]);/*max path from (1,1) to (i,j)*/
	repi(i,n,1)repi(j,m,1)ans12[i][j]=a[i][j]+max(ans12[i+1][j],ans12[i][j+1]);/*max path from (n,m) to (i,j)*/
	repi(i,n,1)rep(j,1,m)ans21[i][j]=a[i][j]+max(ans21[i+1][j],ans21[i][j-1]);/*max path from (n,1) to (i,j)*/
	repi(j,m,1)rep(i,1,n)ans22[i][j]=a[i][j]+max(ans22[i][j+1],ans22[i-1][j]);/*max path from (1,m) to (i,j)*/
	rep(i,2,n-1)
		rep(j,2,m-1){
			ans=max(ans,ans11[i-1][j]+ans12[i+1][j]+ans21[i][j-1]+ans22[i][j+1]);
			ans=max(ans,ans21[i+1][j]+ans22[i-1][j]+ans11[i][j-1]+ans12[i][j+1]);
		}
	cout<<ans<<endl;
	//exectime();
	return 0;
}
