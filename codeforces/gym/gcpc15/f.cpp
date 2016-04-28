/* Author: Hemanth Kumar Veeranki */
/* handle : harry7 */

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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repi(i,a,b) for(int i=a;i>=b;i--)
#define repdf(i,a,b,d) for(int i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(int i=a;i>=b;i-=d)
#define repl(i,a,b) for (int i=a;i<b;i++)
#define repil(i,a,b) for (int i=a;i>b;i--)
#define tr(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define rtr(v,it) for( LET(it,v.rbegin()) ; it != v.rend() ; it++)
#define TC() int t;cin>>t;while(t--)

/*space for global variables*/

bool isp[1000006];
VI primes;

#define MAX 1000000
/*Functions */

void sieve(){
	init(isp,0);
	isp[1]=isp[0]=1;
	rep(i,2,MAX)
		if(isp[i]==0)
			repdf(j,2*i,MAX,i)
				isp[j]=1;
	rep(i,2,MAX)if(!isp[i])primes.PB(i);
}


ll mulmod(ll a,ll b,ll c){
	ll x = 0,y=a%c;
	while(b > 0){
		if(b%2 == 1){
			x = (x+y)%c;
		}
		y = (y << 1)%c;
		b >>= 1;
	}
	return x%c;
}

ll modpow(ll a, ll b, ll mod)
{
	ll ret, base;
	ret = 1;
	base = a;
	while (b > 0)
	{
		if (b & 1)
			ret = mulmod(ret, base, mod);
		b >>= 1;
		base = mulmod(base, base, mod);
	}
	return ret;
}


bool miller(ll n,int iteration){
	int cnt = 0;
	ll d,a,x;
	if(n==2)return 1;
	if(n<2 || !(n&01)) return 0;
	d = n-1;
	while(!(d&01)){
		d>>=1;
		cnt++;
	}
	rep(i,1,iteration){
		a = (rand() % (n-1))+1;
		x=modpow(a,d,n);
		if(x == 1||x == n-1)continue;
		repl(j,1,cnt){
			x=modpow(x,2,n);
			if(x == 1)return 0;
			if(x == n-1)break;
		}
		if(x == n-1)continue;
		return 0;
	}
	return 1;
}

bool is_prime(ll n){
	if(n<=1000000)return !isp[n];
	return miller(n,75);

}

/*main code*/

int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	ll n,p,ans=1,cnt;
	sieve();
	cin >> n;
	repl(i,0,primes.size()){
		p=primes[i];
		cnt=1;
		if(p*p*p>n)break;
		while(n%p==0){
			n/=p;
			cnt++;
		}
		ans*=cnt;
	}
	if(is_prime(n))ans*=2;
	else {
		ll sq=sqrt(n);
		if(sq*sq==n && is_prime(sq))ans*=3;
		else if(n!=1)ans*=4;
	}
	cout << ans << endl;
	//exectime();
	return 0;
}
