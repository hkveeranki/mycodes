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

string s[5001];
int cnt[5001][5001];
int c[5001],b[5001];

/*Functions */
//Most Intresting problem I had ever seen :D
void sort1(int a[],int n,int m){
	int i;
	init(c,0);	
	rep(i,0,n-1)c[a[i]]++;
	rep(i,1,m)c[i]+=c[i-1];
	repi(i,n-1,0){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	rep(i,0,n-1)a[i]=b[i];
}
/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int i,n,m,ans=0,j;
	cin>>n>>m;
	rep(i,0,n-1)cin>>s[i];
	rep(i,0,n-1)if(s[i][m-1]=='1') cnt[m-1][i]=1;
	repi(i,m-2,0)
		rep(j,0,n-1){
			if(s[j][i+1]=='1') cnt[i][j]=cnt[i+1][j];
			else cnt[i][j]=0;
			if(s[j][i]=='1') cnt[i][j]++;
			else cnt[i][j]=0;
		}
	rep(i,0,m){
		sort1(cnt[i],n,m);
		rep(j,0,n-1) ans=max(cnt[i][j]*(n-j),ans);
	}
	cout<<ans<<endl;	
	//exectime();
	return 0;
}
