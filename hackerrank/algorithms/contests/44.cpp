/**********************************************************************************************************************************
	
						     Author  : Vivek Nynaru
   						     Handle  : kevin11 

**********************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define SpeedUp std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/* Typedef's for most frequently used DataTypes */

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string,int> msi;
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

/* For variables */

#define LET(x,a) __typeof(a) x(a) 

/* Iterations */

#define rep(i, a, b) for (int i = int(a);i <= int(b); i++)
#define rev(i, a, b) for (int i = int(b);i >= int(a); i--)
#define repi(i, a, b) for (int i = int(a);i < int(b); i++)
#define revi(i, a, b) for (int i = int(b);i > int(a); i--)
#define tr(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define rtr(v,it) for( LET(it,v.rbegin()) ; it != v.rend() ; it++)
#define TC() int tc; scanf("%d",&tc); while(tc--)

/* Initialisation */

#define init(a,b) memset(a,b,sizeof(a))

/* Debugging */

#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

/* Finding */

#define all(a) a.begin(),a.end()
#define LB(a,x) (lower_bound(all(a),x)-a.begin())
#define UB(a,x) (upper_bound(all(a),x)-a.begin())

/**********************************************************************************************************************************
  	
  							Main Code

**********************************************************************************************************************************/
#define N 200000
struct BIT
{
	ll size;
	ll Mul[N],Add[N];
	inline void clear()  // This will be used
	{
		memset(Mul,0,sizeof(Mul));
		memset(Add,0,sizeof(Add));
	}
	inline void BitUpdate(ll *tcs,int idx, ll val) // This is internal
	{
		while(idx<=size)
		{
			tcs[idx]+=val;
			idx+=idx&(-idx);
		}
	}
	inline void Update(ll l, ll r, ll val)  // This will be used
	{
		BitUpdate(Mul,l,val);
		BitUpdate(Mul,r+1,-val);
		BitUpdate(Add,l,val*(l-1));
		BitUpdate(Add,r+1,-val*r);
	}
	inline ll BitQuery(ll *tcs, ll idx) // This is internal
	{
		ll ans=0;
		while(idx)
		{
			ans+=tcs[idx];
			idx-=idx&(-idx);
		}
		return ans;
	}
	inline ll Sum_till(ll idx)     // This is internal // Gives sum till idx
	{
		return BitQuery(Mul,idx)*idx-BitQuery(Add,idx);
	}
	inline ll Query(ll l, ll r)   // This will be used
	{
		return Sum_till(r)-Sum_till(l-1);
	}
};
ll n,m,q;
string typ;
ll X1,Y1,X2,Y2;
ll ptr,val;
ll lptr,rptr;
BIT ans;
int main()
{
	SpeedUp;
	// Do not use endl use \n for better speed
	cin >> n >> m >> q;
	ans.clear();
	ans.size=n+m-1;
	rep(i,1,q)
	{
		cin >> typ;
		if(typ=="Qr")
		{
			cin >> ptr >> val;
			// Here u need to update mat[ptr][1] to mat[ptr][m]
			// Notice that diagonal passing though mat[i][j] is n+j-i
			// So we need to increment frequencies of answer[n+1-ptr] to ans[n+m-ptr] with values  val,2val,3val,.........mval respectively
		}
		if(typ=="Qc")
		{
			cin >> ptr >> val;
			// Here u need to update mat[1][ptr] to mat[n][ptr]
			// so we need to increment frequencies of answer[n+ptr-n] to answer[n+ptr-1] with values nval,(n-1)val,(n-2)val,..... val respectively
		}
		if(typ=="Qs")
		{
			cin >> X1 >> Y1 >> X2 >> Y2 >> val;
			// Here u need to update a grid ....
			// Here we need to increment frequencies of answer[n+Y1-X2] to answer[n+Y1-X1] with values val,2val,3val,..(X2-X1)*val..
			// Also We need to increment frequencies of answer[n+Y1-X1+1] to answer[n+Y2-X1] with values (Y2-Y1)val........val
		}
		if(typ=="Qd")
		{
			cin >> lptr >> rptr;
		}
	}
	return 0;
}
