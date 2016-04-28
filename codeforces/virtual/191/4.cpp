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
#define swap(VAR1,VAR2) VAR1=VAR1^VAR2;VAR2=VAR1^VAR2;VAR1=VAR1^VAR2

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

bool ise[502][502];
VI x;
VI y;
vector<char> typ;
/*Functions */

ll inline ipow(ll a,ll b){ll val=1;while(b){if(b&01)val=(val*a);b>>=1;a=(a*a);}}

void dfs(int a,int b,int val){
	ise[a][b]=0;
	typ.PB('B');
	x.PB(a);
	y.PB(b);
	if(ise[a][b+1])dfs(a,b+1,2);
	if(ise[a+1][b])dfs(a+1,b,2);
	if(ise[a-1][b])dfs(a-1,b,2);
	if(ise[a][b-1])dfs(a,b-1,2);
	if(val==2){
		typ.PB('D');
		x.PB(a);
		y.PB(b);
		typ.PB('R');
		x.PB(a);
		y.PB(b);
	}
}

/*main code*/
int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	string s;
	int i,j,n,m;
	cin>>n>>m;
	rep(i,1,n){
		cin>>s;
		rep(j,0,m-1)if(s[j]=='.')ise[i][j+1]=1;
	}
		rep(i,1,n)rep(j,1,m)if(ise[i][j])dfs(i,j,1);
		cout<<typ.size()<<endl;
		n=typ.size();
		rep(i,0,n-1)printf("%c %d %d\n", typ[i], x[i], y[i]);
	//exectime();
	return 0;
}
