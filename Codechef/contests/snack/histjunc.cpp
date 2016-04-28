/*Hemanth Kumar */

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

/*standard values*/

#define INF 1e18
#define PI 3.14
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
int adjmat[101][101];
/*main code*/
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	TC(){
		int n,m,i,x,y,w,z,j;
		cin>>n>>m;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)adjmat[i][j]=0;
		for(i=1;i<=m;i++){
			cin>>x>>y;
			adjmat[x][y]=adjmat[y][x]=1;
		}
		if(n<=2)cout<<"0 0\n";
		else if(n==3){
			if (adjmat[1][2] && adjmat[2][3] && adjmat[3][1]) cout << 0 << ' ' << 0 << endl;
			else {
				cout << 2 << ' ' << 3 << endl;
				rep(i,1,3) rep(j,i+1,3) if (!adjmat[i][j]) {
					int w = 6 - i - j;
					cout << w << ' ' << 5 << endl;
					cout << i << ' ' << 4 << endl;
					cout << j << ' ' << 4 << endl;
					break;
				}
			}
		}
		else{
			int x = n + 1, y = n + 2, z = n + 3, t = n + 4;
			vector<ipair>res;
		for(i=1;i<=n;i++)res.push_back(make_pair(i, x));
			for(i=1;i<=n;i++) res.push_back(make_pair(i, y));
			res.push_back(make_pair(x, z));
			res.push_back(make_pair(y, t));
			cout << 4 << ' ' << res.size() << endl;
			for(i=0;i<res.size();i++)cout<<res[i].F<<" "<<res[i].S<<endl;
			res.clear();
		}
		cout<<endl;
	}
return 0;
}
