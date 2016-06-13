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

int n,m;
ll a[1001][1001];
ipair M[10][10][1001][1001];
ll sum[1001][1001];
ll powers[20];
int logs[1001];
/*Functions */

void gen_pow(){
	powers[0]=1;
	for(int i = 1;i<=10;i++)powers[i]=powers[i-1]*2;
	for(int i = 1;i<=1000;i++)logs[i]=(log(i)/log(2));
}
void init_sum(){
	repl(i,0,n)
		repl(j,0,m){
			sum[i][j] = a[i][j];
			if(i!=0)
				sum[i][j]+=sum[i-1][j];
			if (j!=0)
				sum[i][j]+=sum[i][j-1];
			if(i!=0 && j!=0)
				sum[i][j]-=sum[i-1][j-1];
		}
}

ll get_sum(int x1,int y1,int x2,int y2){
	return (sum[x2][y2] - ((x1!=0)?sum[x1-1][y2]:0) - ((y1!=0)?sum[x2][y1-1]:0) + ((x1!=0 && y1!=0)?sum[x1-1][y1-1]:0));
}

ipair get_maxi(ipair x,ipair y){
	if (a[x.F][x.S] < a[y.F][y.S])return y;
	return x;
}
void init_max(){
	for(int i = 0;powers[i]<=n;i++)
		for(int j=0;powers[j]<=n;j++)
			for(int x = 0;x+powers[i]-1<n;x++)
				for(int y=0;y+(1<<j)-1<m;y++){
					//		out4(x,y,i,j);
					if ( i == 0 && j == 0)
						M[i][j][x][y] = MP(x,y);
					else if (i == 0)
						M[i][j][x][y] = get_maxi(M[i][j-1][x][y], M[i][j-1][x][y+(1<<(j-1))]);
					else if (j == 0)
						M[i][j][x][y] = get_maxi(M[i-1][j][x][y], M[i-1][j][x+ (1<<(i-1))][y]);
					else 
						M[i][j][x][y] = get_maxi(M[i-1][j-1][x][y],
								get_maxi(M[i-1][j-1][x + (powers[i-1])][y], 
									get_maxi(M[i-1][j-1][x][y+powers[j-1]], M[i-1][j-1][x +powers[i-1]][y+powers[j-1]])));
				}
}

ll get_max(int x,int y,int x1,int y1){
	int k = logs[x1 - x + 1];
	int l = logs[y1 - y + 1];
	ipair ans = get_maxi(M[k][l][x][y], 
			get_maxi(M[k][l][x1 - (powers[k]) + 1][y],
				get_maxi(M[k][l][x][y1 - (powers[l]) + 1],(M[k][l][x1 - (powers[k]) + 1][y1 - (powers[l]) + 1]))));
	return a[ans.F][ans.S];
}

/*main code*/

int main(){
	FastIn;
	cin >> n >> m;
	repl(i,0,n)
		repl(j,0,m)
		cin >> a[i][j];

	gen_pow();
	init_sum();
	init_max();
	int x1,y1,x2,y2;
	/*cout << "Enter indices" << endl;
	  cin >> x1 >> y1 >> x2 >> y2 ;
	  cout << get_max(x1,y1,x2,y2) << endl;
	  */
	clock_t tStart = clock();/* for execution time caluclation*/
	TC(){
		int a,b;
		cin >> a >> b;
		ll ans = 1000000000001;
		for(int i = 0;i<=n-a;i++)
			for(int j = 0;j<=m-b;j++)
			{
				//out4(i,j,i+a-1,j+b-1);
				ll maxm = get_max(i,j,i+a-1,j+b-1);
				ll summ = get_sum(i,j,i+a-1,j+b-1);
				ll tot = (a*b*maxm-summ);
				//out3(maxm,summ,tot);
				ans = min(tot,ans);
			}
		cout << ans << endl;

	}
	//exectime();
	return 0;
}