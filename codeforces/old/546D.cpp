/*Hemanth Kumar */

/*header files*/

#include<bits/stdc++.h>

using namespace std;

/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
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
ll div2[5000001];
ll cnt[5000001];
bool isp[5000001];

/*Space for functions*/

void sieve(){
	init(isp,0);
	div2[2]=2;
	div2[1]=1;
	for (ll i=2;i*i<=5000000;i++){
		if(isp[i]==0) {
			div2[i]=i;
			for(ll j=2*i;j<=5000000;j+=i){
				isp[j]=1;
				div2[j]=i;
			}
		}
	}
}

/*main code*/
int main()
{
	ll i,j;
	init(cnt,0);
	sieve();
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(i=2;i<=5000000;i++){
		if(isp[i])
			cnt[i]=cnt[i/div2[i]]+1;
		else cnt[i]=1;
	}
	for(i=2;i<=5000000;i++)cnt[i]+=cnt[i-1];
	TC(){
		ll a,b;
		cin>>b>>a;
		ll ans=cnt[b]-cnt[a];
		printf("%lld\n",ans);
	}
	return 0;
}
