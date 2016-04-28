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

ull ans[5000001];
int dp[5000001];
/*Functions */

ull gcd(ull a,ull b){
	if(a==0)return b;
	return gcd(b%a,a);
}

/*main code*/
int main()
{
	FastIn;
	init(ans,0);
	ull i,j,a,b,c,p,max1,lim;
	lim=5000000;
	max1=sqrt(lim);
	rep(i,2,max1-1){
		rep(j,1,i-1){
			if((i+j)%2==1 && gcd(i,j)==1){
				a=i*i+j*j;
				b=2*i*j;
				c=i*i-j*j;
				p=a+b+c;
				while(p<=lim) {
					ans[p]++;
					p+=(a+b+c);
				}
			}
		}
	}
	rep(i,1,lim)dp[i]=i;
	rep(i,2,lim){
		if(ans[dp[i-1]]<ans[i]) dp[i]=i;
		else dp[i]=dp[i-1];
	}
	TC(){
		int n,i,ansm=0;
		cin>>n;
		printf("%d\n",dp[n]);
	}
	return 0;
}
