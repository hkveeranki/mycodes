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

/*For variables*/	

#define LET(a) __typeof(a) x(a) 
#define ALL(a) a.begin(),a.end()

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
#define UB(x,a) (upper_bound(ALL(a),x)-a.begin())
#define LB(a,x) (lower_bound(ALL(a),x)-a.begin())
#define NP(a) next_permutation(ALL(a))

/*exponentiation*/


ll inline ipow(ll a,ll b,ll m){ll val=1;a%=m;while(b){if(b&01)val=(val*a)%m;b>>=1;a=(a*a)%m;};return val%m;}
ll inline ipow(ll a,ll b){ll val=1;while(b){if(b&01)val=(val*a);b>>=1;a=(a*a);};return val;}

/* Seive */


/*
#define LIM1 1000001
bitset<LIM1> isp;
vi primes;
inline void seive(){isp.set();isp.reset(0);isp.reset(1);for(int i=2;i*i<LIM1;i++)if(isp[i]){for(int j=i<<1;j<LIM1;j+=i)isp.reset(j);}repl(i,2,LIM1)if(isp[i]){primes.pb(i);}}
*/

/* Totient */

/*
#define LIM4 1000001
int phi[LIM4];
void totient(){repl(i,1,LIM4)phi[i]=i;tr(primes,it)for(int i=*it;i<LIM4;i+=*it)phi[i]-=phi[i]/(*it);}
*/

/* Inverse Modulo */

/*inline ll invmod(ll a, ll b){return (isp[b])?ipow(a,b-2,b):ipow(a,phi[b]-1,b);}*/

/* Combinatorics */

/*
#define LIM2 1000001
ll fact[LIM2];
inline void Fact(){fact[0]=1;repl(i,1,LIM)fact[i]=(i*fact[i-1])%MOD;}
inline ll inv(ll x,ll mod){return ipow(x,mod-2,mod);}
inline ll comb(ll a, ll b){return ((fact[a]*inv(fact[b],MOD)%MOD)*inv(fact[a-b],MOD))%MOD;}
*/

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define repl(i,a,b) for (i=a;i<b;i++)
#define repil(i,a,b) for (i=a;i>b;i--)
#define tr(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define rtr(v,it) for( LET(it,v.rbegin()) ; it != v.rend() ; it++)
#define TC() int t;cin>>t;while(t--)

/*space for global variables*/

#define MAX 10000000
#define inf 10000000000000000

int ST[MAX];
int lazy[MAX];
int input[500001];
ll ans[500001];
ll knapsack[1000][1000];
vector< pair<ll,int> > LIST;

/*Functions */

//update functions written by seeing code at
//1.http://stackoverflow.com/questions/11765838/how-to-implement-segment-trees-with-lazy-propagation/30622980#30622980
//2.http://se7so.blogspot.in/2012/12/segment-trees-and-lazy-propagation.html :D 
//starts here segtree lazy

void update_ST(int node, int a, int b, int i, int j, int value) {
	if(node<MAX && lazy[node] != 777) { 
		ST[node] = min(ST[node],lazy[node]); 

		if(a != b) {
			lazy[node*2] = min(lazy[node*2],lazy[node]);
			lazy[node*2+1] = min(lazy[node*2+1],lazy[node]); 
		}

		lazy[node] = 777; // Reset it
	}

	if(a > b || a > j || b < i)
		return;

	if(a >= i && b <= j) {
		ST[node] = min(ST[node],value);

		if(a != b) {
			lazy[node*2] = min(lazy[node*2],value);
			lazy[node*2+1] = min(lazy[node*2+1],value);
		}

		return;
	}

	update_ST(node*2, a, (a+b)/2, i, j, value);
	update_ST(1+node*2, 1+(a+b)/2, b, i, j, value);
	if(node<MAX)
		ST[node] = min(ST[node*2], ST[node*2+1]);
}

void query_ST(int node, int a, int b) {
	if(node<MAX && lazy[node] != 777) { 
		ST[node] = min(ST[node],lazy[node]); 
		if(a != b) {
			lazy[node*2] = min(lazy[node*2],lazy[node]); 
			lazy[node*2+1] = min(lazy[node*2+1],lazy[node]); 
		}
		lazy[node] = 777;
	}
	if(a>b)
		return;
	if(a==b)
	{
		ans[a-1]=ST[node];
		return;
	}
	query_ST(node*2, a, (a+b)/2);
	query_ST(1+node*2, 1+(a+b)/2, b);
	if(node<MAX)
		ST[node]=min(ST[node*2+1],ST[node*2]);
}

/*main code*/

int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int a,b,c,i,j,k,n,m,pp;	
	TC(){
		cin >> n >> k >> m;
		ll ans1=0;
		repl(j,0,n){
			cin >> input[j];
			ans1+=input[j];
		}
		repl(j,0,17*n) lazy[j]=ST[j]=777;
		repl(j,0,m){
			cin >> a >> b >> c;
			update_ST(1,1,n,a,b,c);
		}
		query_ST(1,1,n);
		LIST.clear();
		LIST.push_back(make_pair(-1,-1));
		repl(j,0,n)
			if(input[j]<0)
				LIST.push_back(make_pair(ans[j],input[j]*-1)); 
		init(knapsack,0);        
		for(j=1;j<LIST.size();j++){
			rep(pp,0,k){
				if(pp-LIST[j].first>=0)
					knapsack[j][pp]=max(knapsack[j-1][pp],knapsack[j-1][pp-LIST[j].first]+LIST[j].second);
				else
					knapsack[j][pp]=knapsack[j-1][pp];
			}
		}
		cout << ans1+knapsack[LIST.size()-1][k] << endl;
	}
	//exectime();
	return 0;
}
