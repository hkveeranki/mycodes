/*Author: Hemanth Kumar Veeranki */

/*handle: harry7*/

/*header files*/

#include<bits/stdc++.h>

using namespace std;

/*typedef's for frequently used*/

typedef long long int ll;
typedef vector<int>VI;
typedef vector<ll>VLI;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
typedef unsigned long long int ull;

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
#define swap(VAR1,VAR2) VAR1=VAR1^VAR2;VAR2=VAR1^VAR2;VAR1=VAR1^VAR2
ll inline ipow(ll a,ll b,ll m){ll val=1;a%=m;while(b){if(b&01)val=(val*a)%m;b>>=1;a=(a*a)%m;};return val%m;}
ll inline ipow(ll a,ll b){ll val=1;while(b){if(b&01)val=(val*a);b>>=1;a=(a*a);};return val;}

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define repl(i,a,b) for (i=a;i<b;i++)
#define repil(i,a,b) for (i=a;i>b;i--)
#define TC() int t;cin>>t;while(t--)

/*space for global variables*/

lpair inp[200005];
ll a[200005];
pair<lpair,int> m[200005];
int ans[200005];
set< pair<ll,int> > s;

/*Functions */

/*main code*/

int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int i,n,M,j;
	ll x,y;
	cin>>n>>M;
	rep(i,1,n)cin>>inp[i].F>>inp[i].S;
	rep(i,1,n-1) m[i]=MP(MP(inp[i+1].S-inp[i].F,inp[i+1].F-inp[i].S),i);
	rep(i,1,M){
		cin>>a[i];
		s.insert(MP(a[i],i));
	}
	sort(m+1,m+n);
	rep(i,1,n-1){
		set< pair<ll,int> >::iterator it=s.lower_bound(MP(m[i].F.S,0));
		if(it==s.end()||it->F>m[i].F.F){
			//cout<<"Broke for "<<m[i].F.S<<" with "<<it->first<<endl;
			cout<<"No\n";
			return 0;
		}
		else{
			//cout<<"Entered for "<<m[i].F.S<<" with "<<it->first<<endl;
		ans[m[i].S]=it->S;
		s.erase(it);
		}
	}
	cout<<"Yes\n";
	rep(i,1,n-1)cout<<ans[i]<<" ";cout<<endl;
	//exectime();
	return 0;
}
