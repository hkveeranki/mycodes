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
#define mod 1000000007
ll n,m,q;
string typ;
ll X1,Y1,X2,Y2;
ll ptr,val;
ll lptr,rptr;
ll ans[N];
int main()
{
	SpeedUp;
	// Do not use endl use \n for better speed
	cin >> n >> m >> q;
	rep(i,1,q)
	{
		cin >> typ;
		if(typ=="Qr")
		{
			cin >> ptr >> val;
			// Here u need to update mat[ptr][1] to mat[ptr][m]
			// Notice that diagonal passing though mat[i][j] is n+j-i
			// So we need to increment frequencies of answer[n+1-ptr] to ans[n+m-ptr] with values  val,2val,3val,.........mval respectively
			ll inc=val;
			ll idx=n+1-ptr;
			rep(j,1,m)
			{
				ans[idx]=(ans[idx]+inc)%mod;
				inc+=val;
				idx++;
			}
		}
		if(typ=="Qc")
		{
			cin >> ptr >> val;
			// Here u need to update mat[1][ptr] to mat[n][ptr]
			// so we need to increment frequencies of answer[n+ptr-n] to answer[n+ptr-1] with values nval,(n-1)val,(n-2)val,..... val respectively
			ll inc=n*val;
			ll idx=ptr;
			rep(j,1,n)
			{
				ans[idx]=(ans[idx]+inc)%mod;
				inc-=val;
				idx++;
			}
		}
		if(typ=="Qs")
		{
			cin >> X1 >> Y1 >> X2 >> Y2 >> val;
			// Here u need to update a grid ....
			// Here we need to increment frequencies of answer[n+Y1-X2] to answer[n+Y1-X1] with values val,2val,3val,..(X2-X1)*val..
			// Also We need to increment frequencies of answer[n+Y1-X1+1] to answer[n+Y2-X1] with values (Y2-Y1)val........val
			ll inc=val;
			ll idx=n+Y1-X2;
			while(idx<=n+Y1-X1)
			{
				ans[idx]=(ans[idx]+inc)%mod;
				inc+=val;
				idx++;
			}
			inc=(Y2-Y1)*val;
			idx=n+Y1-X1+1;
			while(inc>=val)
			{
				ans[idx]=(ans[idx]+inc)%mod;
				idx++;
				inc-=val;
			}
		}
		if(typ=="Qd")
		{
			cin >> lptr >> rptr;
			ll res=0;
			rep(j,lptr,rptr)
				res=(res+ans[j])%mod;
			cout << res << endl;
		}
	}
	return 0;
}
