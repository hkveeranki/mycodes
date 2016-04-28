/*Author: Hemanth Kumar Veeranki */

/*handle: harry7*/

/*header files*/

#include<bits/stdc++.h>

using namespace std;

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
#define MAX 1000006

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

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)

/*typedef's for frequently used*/

typedef long long int ll;
typedef vector<int>VI;
typedef vector<ll>VLI;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
typedef unsigned long long int ull;

/*space for global variables*/

#define maxn 8

/*Functions */

struct point {
	ll x[3];
	void inline in() {cin>>x[0]>>x[1]>>x[2];}
	void inline outp() { cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;}
	point operator - (const point& u) {
		point ret;
		int i;
		rep(i,0,2)  ret.x[i] = x[i] - u.x[i];
		return ret;
	}
};
point p[maxn+5];
ll dis (point u) {
	ll ret = 0;
	int i;
	rep(i,0,2) ret += u.x[i] * u.x[i];
	return ret;
}

bool check (int k) {
	int mv = 0,i;
	ll d[maxn+5];
	rep(i,0,maxn-1) {
		if (i == k)
			continue;
		d[mv++] = dis(p[k] - p[i]);
	}
	sort(d, d + 7);
	if (d[0] == 0) return 0;
	if (d[0] != d[1] || d[0] != d[2]) return 0;
	if (d[3] != d[4] || d[3] != d[5]) return 0;
	if (d[0] * 2 != d[3] || d[0] * 3 != d[6])return 0;
	return 1;
}

bool checker () {
	int i;
	rep(i,0,maxn-1) if (!check(i)) return 0;
cout<<"YES\n";
	rep(i,0,maxn-1) p[i].outp();
	return 1;
}
bool solve (int d) {
	if (d == maxn) return checker();
	sort(p[d].x, p[d].x + 3);
	do {
		if (solve(d+1)) return 1;
	} while (next_permutation(p[d].x, p[d].x + 3));
	return 0;
}
/*main code*/
int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int i;
	rep(i,0,maxn-1)	p[i].in();
	if (!solve(1)) cout<<"NO\n";
	//exectime();
	return 0;
}
