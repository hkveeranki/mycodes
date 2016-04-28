/**********************************************************************************************************************************

Author  : Vivek Nynaru
Handle  : kevin11 

 **********************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define SpeedUp std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/* Typedef's for most frequently used DataTypes */

typedef long long int ll;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef pair < int , int > ii;
typedef pair < ll , ll > llll;
typedef vector < ii > vii;
typedef vector < llll > vllll;
typedef set < int > si;
typedef set < ll > sl;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef map < string , int > msi;
typedef priority_queue < ll , vector < ll > , greater < ll > > minheap;
typedef priority_queue < ll , vector < ll > , less < ll > > maxheap;

/* Most frequently used Constants */

#define INF 1000000000000000000
#define PI M_PI
#define E M_E
#define MOD 1000000007

/* Most frequently used Functions */

#define pb push_back
#define pp pop_back
#define mp make_pair
#define F first
#define S second
#define setbits  __builtin_popcount

/* For variables */

#define LET(x,a) __typeof(a) x(a) 

/* Iterations */

#define rep(i, a, b) for (int i = int(a);i <= int(b); i++)
#define rev(i, a, b) for (int i = int(b);i >= int(a); i--)
#define repi(i, a, b) for (int i = int(a);i < int(b); i++)
#define revi(i, a, b) for (int i = int(b);i > int(a); i--)
#define tr(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define rtr(v,it) for( LET(it,v.rbegin()) ; it != v.rend() ; it++)
#define TC() int tc;cin >> tc; while(tc--)

/* Initialisation */

#define init(a,b) memset(a,b,sizeof(a))

/* Debugging */

#define echo(x) cerr << "It's fine at position : " << x << "\n";
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

/* Finding */

#define ALL(a) a.begin(),a.end()
#define LB(a,x) (lower_bound(ALL(a),x)-a.begin())
#define UB(a,x) (upper_bound(ALL(a),x)-a.begin())
inline ll f(ll idx)
{
	//Here Goes the function for search

}
inline ll g(ll val, ll key, ll ret)
{
	// Here goes ur final condition
	return (val<=key)?ret:ret-1; // This is default lowerbound .......
	// return ret;               // If f(idx) must be atleast equal to key and idx must be as small as possible
}
inline ll lowbound(ll l,ll r,ll key){ll mid,val;while(l<r){mid=(l+r)>>1;val=f(mid);if(key>val){l=mid+1;}else{r=mid;}}return g(f(l),key,l);}
//inline ll upbound(ll l, ll r,ll key){ll mid,val;while(l<r){mid=(l+r)>>1;val=f(mid);if(key<=val){r=mid;}else{l=mid+1;}}return r;}

/* Movement */

// int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

/* permutation */

#define nperm(A) next_permutation(ALL(A)) // usage : returns 0 if its last permutation else 1 and sets the permuation in A

/* Exponentiation */

inline ll Pow(ll a, ll b, ll mod){ll res=1;while(b){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
inline ll Poww(ll a, ll b){ll res=1;while(b){if(b&1)res=res*a;a=a*a;b>>=1;}return res;}
inline ll inv(ll x){return Pow(x,MOD-2,MOD);}

/* Seive */

/*
#define LIM1 1000001
bitset<LIM1> isprime;
vi primes;
inline void seive(){isprime.set();isprime.reset(0);isprime.reset(1);for(int i=2;i*i<LIM1;i++)if(isprime[i]){for(int j=i<<1;j<LIM1;j+=i)isprime.reset(j);}repi(i,2,LIM1)if(isprime[i]){primes.pb(i);}}
*/

/* Totient */

/*
#define LIM4 1000001
int phi[LIM4];
void totient(){repi(i,1,LIM4)phi[i]=i;tr(primes,it)for(int i=*it;i<LIM4;i+=*it)phi[i]-=phi[i]/(*it);}
*/

/* Inverse Modulo */

// To use uncomment Totient and Seive
//inline ll invmod(ll a, ll b){return (isprime[b])?Pow(a,b-2,b):Pow(a,phi[b]-1,b);}

/* Combinatorics */

// Method 1 ---->  To use in a function Uncomment next line and call Fact() once and then comb(a,b) when needed

/*
#define LIM2 1000001
ll fact[LIM2];
inline void Fact(){fact[0]=1;repi(i,1,LIM2)fact[i]=(i*fact[i-1])%MOD;}
inline ll inv(ll x,ll mod){return Pow(x,mod-2,mod);}
inline ll comb(ll a, ll b){if(a<b)return 0;return ((fact[a]*inv(fact[b],MOD)%MOD)*inv(fact[a-b],MOD))%MOD;}
*/

// Method 2 ----> To use in a function Uncomment next line and call COMB() once and then C[a][b] when needed

/*
#define LIM3 5001
ll C[LIM3][LIM3];
inline void COMB(){repi(i,0,LIM3){C[i][0]=C[i][i]=1;rep(j,1,i>>1)C[i][j]=C[i][i-j]=(C[i-1][j]+C[i-1][j-1])%MOD;}}
*/

/**********************************************************************************************************************************

  Main Code

 **********************************************************************************************************************************/
#define SIZE 9500000
#define N 500001
ll st[SIZE],add[SIZE],mul[SIZE],vals[N],arr[N];
ll upd[SIZE];
bitset<SIZE> todo;
inline void build(int in,int s,int e)
{
	if(s>e)
		return;
	if(s==e)
	{
		st[in]=arr[s];
		return;
	}
	build(in<<1,s,(s+e)/2);
	build((in<<1)+1,1+(s+e)/2,e);
	st[in]=st[2*in]+st[2*in+1];
}
inline void update1(int in,int s,int e,int i,int j,ll val)
{
	if(todo[in])
	{
		st[in]=(upd[in]*(e-s+1))%MOD;
		st[in]=(((st[in]*mul[in])%MOD)+add[in])%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD;
			upd[2*in]=upd[in];
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD;
			upd[2*in+1]=upd[in];
			mul[2*in]=mul[in];
			mul[2*in+1]=mul[in];
			todo.set(2*in);
			todo.set(2*in+1);
		}
		todo.reset(in);
		upd[in]=0;
		add[in]=0;
		mul[in]=1;
	}
	if(add[in] || mul[in]!=1)
	{
		st[in]=(((st[in]*mul[in])%MOD)+add[in])%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(add[2*in]+((((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD))%MOD;
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(add[2*in+1]+((((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD))%MOD;
			mul[2*in]=(mul[2*in]*mul[in])%MOD;
			mul[2*in+1]=(mul[2*in+1]*mul[in])%MOD;
		}
		add[in]=0;
		mul[in]=1;
	}
	if(s>e || s>j || e<i) // To Check Boundary
		return;
	if(s>=i && e<=j) // if strictly inside update
	{                          
		st[in]=(st[in]+(((e-s+1)*val)%MOD))%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(add[2*in]+((val*temp)%MOD))%MOD;
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(add[2*in+1]+((val*temp)%MOD))%MOD;
		}
		return;
	}
	update1(in<<1,s,(s+e)/2,i,j,val);
	update1((in<<1)+1,1+(s+e)/2,e,i,j,val);
	st[in]=(st[2*in]+st[2*in+1])%MOD;
}
inline void update2(int in,int s,int e,int i,int j,ll val)
{
	if(todo[in])
	{
		st[in]=(upd[in]*(e-s+1))%MOD;
		st[in]=(((st[in]*mul[in])%MOD)+add[in])%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD;
			upd[2*in]=upd[in];
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD;
			upd[2*in+1]=upd[in];
			mul[2*in]=mul[in];
			mul[2*in+1]=mul[in];
			todo.set(2*in);
			todo.set(2*in+1);
		}
		todo.reset(in);
		upd[in]=0;
		add[in]=0;
		mul[in]=1;
	}
	if(add[in] || mul[in]!=1)
	{
		st[in]=(((st[in]*mul[in])%MOD)+add[in])%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(add[2*in]+((((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD))%MOD;
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(add[2*in+1]+((((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD))%MOD;
			mul[2*in]=(mul[2*in]*mul[in])%MOD;
			mul[2*in+1]=(mul[2*in+1]*mul[in])%MOD;
		}
		add[in]=0;
		mul[in]=1;
	}
	if(s>e || s>j || e<i) // To Check Boundary
		return;
	if(s>=i && e<=j) // if strictly inside update
	{                          
		st[in]=(st[in]*val)%MOD;
		if(s!=e)
		{
			add[2*in]=(add[2*in]*val)%MOD;
			add[2*in+1]=(add[2*in+1]*val)%MOD;
			mul[2*in]=(mul[2*in]*val)%MOD;
			mul[2*in+1]=(mul[2*in+1]*val)%MOD;
		}
		return;
	}
	update2(in<<1,s,(s+e)/2,i,j,val);
	update2((in<<1)+1,1+(s+e)/2,e,i,j,val);
	st[in]=(st[2*in]+st[2*in+1])%MOD;
}
inline void update3(int in,int s,int e,int i,int j,ll val)
{
	if(todo[in])
	{
		//echo("hi1");
		st[in]=(upd[in]*(e-s+1))%MOD;
		st[in]=(((st[in]*mul[in])%MOD)+add[in])%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD;
			upd[2*in]=upd[in];
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD;
			upd[2*in+1]=upd[in];
			mul[2*in]=mul[in];
			mul[2*in+1]=mul[in];
			todo.set(2*in);
			todo.set(2*in+1);
		}
		todo.reset(in);
		upd[in]=0;
		add[in]=0;
		mul[in]=1;
	}
	if(add[in] || mul[in]!=1)
	{
		//echo("hi");
		st[in]=(((st[in]*mul[in])%MOD)+add[in])%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(add[2*in]+((((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD))%MOD;
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(add[2*in+1]+((((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD))%MOD;
			mul[2*in]=(mul[2*in]*mul[in])%MOD;
			mul[2*in+1]=(mul[2*in+1]*mul[in])%MOD;
		}
		add[in]=0;
		mul[in]=1;
	}
	if(s>e || s>j || e<i) // To Check Boundary
		return;
	if(s>=i && e<=j) // if strictly inside update
	{                          
		st[in]=((e-s+1)*val)%MOD;
		if(s!=e)
		{
			add[2*in]=add[2*in+1]=0;
			mul[2*in]=mul[2*in+1]=1;
			upd[2*in]=upd[2*in+1]=val;
			todo.set(2*in);
			todo.set(2*in+1);
		}
		return;
	}
	update3(in<<1,s,(s+e)/2,i,j,val);
	update3((in<<1)+1,1+(s+e)/2,e,i,j,val);
	st[in]=(st[2*in]+st[2*in+1])%MOD;
}
ll ret=0;
inline void query(int in,int s,int e,int i,int j)
{
	if(todo[in])
	{
		st[in]=(upd[in]*(e-s+1))%MOD;
		st[in]=(((st[in]*mul[in])%MOD)+add[in])%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD;
			upd[2*in]=upd[in];
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD;
			upd[2*in+1]=upd[in];
			mul[2*in]=mul[in];
			mul[2*in+1]=mul[in];
			todo.set(2*in);
			todo.set(2*in+1);
		}
		todo.reset(in);
		upd[in]=0;
		add[in]=0;
		mul[in]=1;
	}
	if(add[in] || mul[in]!=1)
	{
		st[in]=(((st[in]*mul[in])%MOD)+add[in])%MOD;
		if(s!=e)
		{
			int temp;
			temp=((s+e)/2)-s+1;
			add[2*in]=(add[2*in]+((((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD))%MOD;
			temp=e-(1+(s+e)/2)+1;
			add[2*in+1]=(add[2*in+1]+((((add[in]*inv(e-s+1))%MOD)*((ll)(temp)))%MOD))%MOD;
			mul[2*in]=(mul[2*in]*mul[in])%MOD;
			mul[2*in+1]=(mul[2*in+1]*mul[in])%MOD;
		}
		add[in]=0;
		mul[in]=1;
	}
	if(s>e || s>j || e<i) // To Check Boundary
		return;
	if(s>=i && e<=j) // if strictly inside update
	{                          
		/*st[in]=((e-s+1)*val)%MOD;
		if(s!=e)
		{
			add[2*in]=add[2*in+1]=0;
			mul[2*in]=mul[2*in+1]=1;
			upd[2*in]=upd[2*in+1]=val;
			todo.set(2*in);
			todo.set(2*in+1);
		}
		return;*/
		ret=(ret+st[in])%MOD;
		return;
	}
	query(in<<1,s,(s+e)/2,i,j);
	query((in<<1)+1,1+(s+e)/2,e,i,j);
	//st[in]=(st[2*in]+st[2*in+1])%MOD;
}
/*inline void updateall(int in,int s,int e)
{
	if(in<SIZE && lazy[in]!=201) // To allocate previous stuff
	{
		st[in]=min(lazy[in],st[in]);
		if(s!=e)
		{
			lazy[2*in]=min(lazy[2*in],lazy[in]);
			lazy[2*in+1]=min(lazy[in],lazy[2*in+1]);
		}
		lazy[in]=201;
	}
	if(s>e) // To Check Boundary
		return;
	if(s==e)
	{
		vals[s]=st[in];
		return;
	}
	updateall(in<<1,s,(s+e)/2);
	updateall((in<<1)+1,1+(s+e)/2,e);
	if(in<SIZE)
		st[in]=min(st[2*in],st[2*in+1]);
}*/
int n,q,typ,l,r;
ll val;
int main()
{
	//SpeedUp;
	//clock_t tStart = clock();
	//Fact();
	//COMB();
	//seive();
	//totient();
	cin >> n >> q;
	rep(i,1,20*n)
		mul[i]=1,add[i]=upd[i]=0;
	todo.reset();
	rep(i,1,n)
		scanf("%lld",&arr[i]);
	build(1,1,n);
	while(q--)
	{
		scanf("%d%d%d",&typ,&l,&r);
		if(typ==1)
		{
		scanf("%lld",&val);
			update1(1,1,n,l,r,val);
		}
		else if(typ==2)
		{
		scanf("%lld",&val);
			update2(1,1,n,l,r,val);
		}
		else if(typ==3)
		{
		scanf("%lld",&val);
			update3(1,1,n,l,r,val);
		}
		else
		{
			ret=0;
			query(1,1,n,l,r);
			cout << ret << "\n";
		}
			
	}
	//exectime();
	return 0;
}

