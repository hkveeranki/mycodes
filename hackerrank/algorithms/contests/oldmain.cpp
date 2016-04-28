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
#define inf 100000000
ll n,m,q;
char type[1000];
ll X1,Y1,X2,Y2;
ll ptr,val;
ll lptr,rptr;
ll ans[N];
int tree[3000001];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = ans[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = (tree[node*2]+tree[node*2+1])%MOD; // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a == b) { // Leaf node
    		tree[node] = (tree[node]+value*(a-i+1))%MOD;
    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = (tree[node*2]+tree[node*2+1])%MOD; // Updating root with max value
}

void rev_update_tree(int node, int a, int b, int i, int j, int value) {

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a == b) { // Leaf node
    		tree[node] = (tree[node]+value*(j-a+1))%MOD;
    		return;
	}

	rev_update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	rev_update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = (tree[node*2]+tree[node*2+1])%MOD; // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 0; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
        {
		return tree[node];
    }

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = (q1+q2)%MOD; // Return final result

	return res;
}

int main()
{
	// Do not use endl use \n for better speed
	scanf("%lld%lld%lld", &n, &m, &q);
    build_tree(1, 0, n+m-1);
	rep(i,1,q)
	{
		scanf("%s", type);
        string typ(type);
		if(typ=="Qr")
		{
			scanf("%lld%lld",&ptr,&val);
			// Here u need to update mat[ptr][1] to mat[ptr][m]
			// Notice that diagonal passing though mat[i][j] is n+j-i
			// So we need to increment frequencies of answer[n+1-ptr] to ans[n+m-ptr] with values  val,2val,3val,.........mval respectively
			update_tree(1, 0, n+m-1, n-ptr+1, n-ptr+m, val);
		}
		if(typ=="Qc")
		{
			scanf("%lld%lld", &ptr,&val);
			// Here u need to update mat[1][ptr] to mat[n][ptr]
			// so we need to increment frequencies of answer[n+ptr-n] to answer[n+ptr-1] with values nval,(n-1)val,(n-2)val,..... val respectively
            rev_update_tree(1, 0, n+m-1, ptr, n+ptr-1, val);
		}
		if(typ=="Qs")
		{
            scanf("%lld%lld%lld%lld%lld", &X1, &Y1, &X2, &Y2, &val);
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
                update_tree(1, 0, n+m-1, cur, cur, min(i,j)*val);
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
                update_tree(1, 0, n+m-1, cur, cur, min(i,j)*val);
                cur++;
                j--;
            }
		}
		if(typ=="Qd")
		{
			scanf("%lld%lld", &lptr, &rptr);
			printf("%lld\n", query_tree(1, 0, n+m-1, lptr, rptr));
		}
	}
	return 0;
}
