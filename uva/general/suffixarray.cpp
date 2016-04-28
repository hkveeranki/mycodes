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

struct info{
	int frank,lrank,rank;
};
int s[20][1000001];

/*Functions */

bool cmp(info a,info b){
	if(a.frank==b.frank)return a.lrank<b.lrank;
	return a.frank<b.frank;
}

/*main code*/

int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	string S;
	int i,j,cnt,n;
	cin>>S;
	n=S.length();
	info a[n];
	rep(i,0,n-1)s[0][i]=S[i]-'a';
	for(j=1,cnt=1;cnt<n;j++,cnt*=2){
		rep(i,0,n-1){
			a[i].frank=s[j-1][i];
			a[i].lrank=(i+cnt)<n?s[j-1][i+cnt]:-1;
			a[i].rank=i;
		}
		sort(a,a+n,cmp);
		int cur=0;
		s[j][a[0].rank]=0;
		rep(i,1,n-1){
			if(a[i].frank!=a[i-1].frank||a[i].lrank!=a[i-1].lrank)cur++;
			s[j][a[i].rank]=cur;
		}
	}
	rep(i,0,n-1)cout<<a[i].rank<<" ";cout<<endl;
	//exectime();
	return 0;
}
