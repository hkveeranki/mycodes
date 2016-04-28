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

bool dp[202][22];
int price[21][21];
int num[21];

/*main code*/
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	TC(){
		int m,i,j,k,c;
		cin>>m>>c;
		rep(i,1,c){
			cin>>num[i];
			rep(j,1,num[i])cin>>price[i][j];
		}
		/*Dp Starts*/
		init(dp,false);
		rep(i,1,num[1]) if(m-price[1][i]>=0) dp[m-price[1][i]][1]=true;
		rep(i,2,c){
			rep(j,0,m-1){if(dp[j][i-1])
				rep(k,1,num[i]){
					if(j-price[i][k]>=0)dp[j-price[i][k]][i]=1;
				}
			}
		}
		rep(i,0,m){
			if(dp[i][c])break;
		}
		if(i==m+1)printf("no solution\n");
		else
			printf("%d\n",m-i);
	}
	return 0;
}
