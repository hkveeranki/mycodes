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

#define MOD 1000000007
#define LIM2 1000001
//inline ll inv(ll x,ll mod){return ipow(x,mod-2,mod);}
//inline ll comb(ll a, ll b){return ((fact[a]*inv(fact[b],MOD)%MOD)*inv(fact[a-b],MOD))%MOD;}


/*space for global variables*/

int cnt[100005],cnt2[100005],ans[100005];

/*Functions */

VI zfunc(string s){
	int i,k,l=0,r=0,n=s.length();
	VI z(n);
	repl(i,1,n){
		if(i>r){
			l=r=i;
			while(r<n && s[r]==s[r-l])r++;
			z[i]=(r-l);r--;
		}
		else{
			k=i-l;
			if(z[k]<(r-i+1))z[i]=z[k];
			else{
				l=i;
				while(r<n && s[r-l]==s[r])r++;
				z[i]=r-l;r--;
			}
		}
	}
	return z;
}

int inv[100010];
int fact[100010];

int C(int n, int k) {
	int res = 1;
	res = (res * 1ll * fact[n]) % MOD;
	res = (res * 1ll * inv[k]) % MOD;
	res = (res * 1ll * inv[n-k]) % MOD;

	return res;
}


/*main code*/

int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int n,i,j,q;
	TC(){
		cin>>n;
		cin>>q;
		string s;
		cin>>s;
		fact[0]=inv[0]=1;
		for(int i = 1; i <= n; ++i) {
			fact[i] = (fact[i-1] * 1ll * i) % MOD;
			inv[i] = ipow(fact[i], MOD-2,MOD);
			ans[i] = 0;
			cnt2[i] = 0;
		}
		repl(i,0,n){
			VI z=zfunc(s.substr(i,n-i));
			rep(j,0,n)cnt[j]=0;
			repl(j,0,(int)z.size()){
				cnt[0]++;
				cnt[z[j]+1]--;
			}
			rep(j,1,n){
				cnt[j]+=cnt[j-1];
				cnt2[cnt[j]]++;
			}
			ans[1]+=(n-i);

		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= i; ++j) {
				ans[j+1] += (cnt2[i] * 1ll * C(i, j)) % MOD;
				ans[j+1] %= MOD;
			}
		}
		while(q--){
			cin>>i;
			if(i>n)cout<<0<<"\n";
			else cout<<ans[i]<<"\n";
		}
	}
	//exectime();
	return 0;
}
