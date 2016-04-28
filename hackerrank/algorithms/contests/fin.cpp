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
#define N 2000000
ll n,m,q;
string typ;
ll X1,Y1,X2,Y2;
ll ptr,val;
ll lptr,rptr;
ll ans[N];
char type[1001];
int main()
{
	SpeedUp;
	// Do not use endl use \n for better speed
	scanf("%lld%lld%lld",&n,&m,&q);
	rep(i,1,q)
	{
		scanf("%s",type);
string typ(type);
		if(typ=="Qr")
		{
			scanf("%lld%lld",&ptr,&val);
			// Here u need to update mat[ptr][1] to mat[ptr][m]
			// Notice that diagonal passing though mat[i][j] is n+j-i
			// So we need to increment frequencies of answer[n+1-ptr] to ans[n+m-ptr] with values  val,2val,3val,.........mval respectively
			ll inc=val;
			ll idx=n-ptr;
			rep(j,1,m)
			{
				ans[idx+j]=(ans[idx+j]+inc)%MOD;
				inc=(inc+val)%MOD;
			}
		}
		if(typ=="Qc")
		{
			scanf("%lld%lld",&ptr,&val);
			// Here u need to update mat[1][ptr] to mat[n][ptr]
			// so we need to increment frequencies of answer[n+ptr-n] to answer[n+ptr-1] with values nval,(n-1)val,(n-2)val,..... val respectively
			ll inc=val;
			ll idx=n+ptr;
			rep(j,1,n)
			{
				ans[idx-j]=(ans[idx-j]+inc)%MOD;
				inc=(inc+val)%MOD;
			}
		}
		if(typ=="Qs")
		{
			scanf("%lld%lld%lld%lld%lld",&X1,&Y1,&X2,&Y2,&val);
			// Here u need to update a grid ....
			// Here we need to increment frequencies of answer[n+Y1-X2] to answer[n+Y1-X1] with values val,2val,3val,..(X2-X1)*val..
			// Also We need to increment frequencies of answer[n+Y1-X1+1] to answer[n+Y2-X1] with values (Y2-Y1)val........val
            ll i,j;
            i=X2-X1+1;
            j=Y2-Y1+1;
            ll cur=n-X1+Y1;
            while(1)
            {
                if(min(i,j)==0)
                    break;
                ans[cur]=(ans[cur]+(min(i,j)*val)%MOD)%MOD;
                cur--;
                i--;
            }
            cur=n-X1+Y1+1;
            i=X2-X1+1;
            j=Y2-Y1+1;
            j--;
            while(1)
            {
                if(min(i,j)==0)
                    break;
                ans[cur]=(ans[cur]+(min(i,j)*val)%MOD)%MOD;
                cur++;
                j--;
            }
		}
		if(typ=="Qd")
		{
				scanf("%lld%lld",&lptr,&rptr);
			ll res=0;
			rep(j,lptr,rptr)
				res=(res+ans[j])%MOD;
			cout << res << endl;
		}
	}
	return 0;
}


