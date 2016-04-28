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
#define eps 1e-4

/*Frequent functions*/

#define sqr(x) ((x)*(x))
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

int i;
double d[3], A[3], S, r, ans, n, gcd1;

struct point {
    double x, y;
} p[4];

/*Functions */


double inline dist(point a, point b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));}

double area() {
    double s = 0;
    for (int i = 0; i < 3; i++) s += p[i].x * p[i + 1].y - p[i + 1].x * p[i].y;
    return fabs(s) / 2;
}

double inline angle(double a, double b, double c) { return acos((b*b + c*c - a*a) / (2 * b * c));}

double gcd(double x, double y) {
    while (fabs(x) > eps && fabs(y) > eps) {
        if (x > y) x -= floor(x / y) * y; else
               y -= floor(y / x) * x;
    }
    return x + y;
}

/*main code*/
int main(){
    rep(i,0,2) scanf("%lf %lf", &p[i].x, &p[i].y);
    p[3] = p[0];
    rep(i,0,2) d[i] = dist(p[i], p[i+1]);
    S = area();
    r = (d[0]*d[1]*d[2])/(4*S);
    A[0] = angle(d[0], d[1], d[2]);
    A[1] = angle(d[1], d[2], d[0]);
    A[2] = angle(d[2], d[0], d[1]);
    gcd1 = gcd(gcd(A[0], A[1]), A[2]);
    n = PI / gcd1;
    ans = n / 2 * r * r * sin(2*PI/n);
    printf("%lf\n", ans);
}
