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

int parent[100005],type[100005];

/*Functions */

int find(int x){
	if(parent[x]==x)return x;
	int p=parent[x];
	parent[x]=find(parent[x]);
	type[x]=(type[x]+type[p]+1)%2;//dividing it into one of two sets(in case of bipartite it will be ok else fails)
	return parent[x];
}
void uni(int x,int y,int u,int v,int typ){
	parent[x]=y;
	type[x]=(type[v]-type[u]+typ)%2;//same followed here
}
/*main code*/

int main(){//solving by dsu , i thought it was easy
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int i,x,y,px,py,typ,n,m;
	cin>>n>>m;
	rep(i,1,n){//initialisations :P .
		parent[i]=i;
		type[i]=1;
	}
	bool fl=true;
	rep(i,1,m){
		cin>>x>>y>>typ;
		if(!fl)continue;//lite no need to process we know already that its -1
		px=find(x);
		py=find(y);
		if(px==py){
			if(typ==0 && type[x]==type[y])fl=false;//cant be bi-partite
			else if(typ==1 && type[x]!=type[y])fl=false;//same.. Think why ?
		}
		else uni(px,py,x,y,typ);
	}
	if(!fl)cout<<"0\n";
	else {
		int num=0;
		rep(i,1,n)if(parent[i]==i)num++;//counting number of connected components :D .
		cout<<ipow(2,num-1,1000000007);
	}
	//exectime();
	return 0;
}
