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


/*Functions */

ll gcd(ll a,ll b){
	if(a==0)return b;
	return gcd(b%a,a);
}
/*main code*/
int main()
{
	FastIn;
	TC(){
		ll n,i,j,a,b,c,ans=-1,d,lim,k;
		cin>>n;
		lim=sqrt(n/2);
		rep(i,2,lim)
			if((n/2)%i==0){
				j=i+1;
				if(i%2==1)j++;
				while(j<2*i && j<=n/(2*i)){
					if((n/(2*i))%j==0 &&  gcd(j,i)==1){
						d=n/2/(i*j);
						k=j-i;
						a=d*(i*i-k*k);
						b=d*(2*i*k);
						c=d*(i*i+k*k);
						if(a+b+c==n) ans=max(ans,a*b*c);
					}
					j+=2;
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}
