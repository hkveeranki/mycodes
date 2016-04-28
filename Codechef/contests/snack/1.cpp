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


/*main code*/
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	TC(){
		int vote[51],a[51];
		bool mark[51],fl=0;
		init(mark,0);
		int n,i,j,x,y;
		cin>>n;
		rep(i,1,n){
			cin>>x;
			a.PB(MP(x,i));
		}
		sort(a.begin(),a,end());
		int sum=0;
		rep(i,0,n-1){
			sum+=a[i].F;
			if(a[i].F>=n||sum>n){
				fl=1;
				break;
			}
		}
		if(sum==n && fl==0){
			for(i=n-1;i>=0;i++){
				int cnt=0;
				for(j=n-1;j>=0;j--){
					if(cnt==a[i].F)break;
					if(i!=j && mark[j]==0){
						vote[j]=a[i].S+1;
						mark[j]=1;
						cnt++;
					}
				}
			}
			rep(i,0,n-1)printf("%d ",vote[i]);printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
