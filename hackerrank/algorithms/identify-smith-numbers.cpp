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


/*Functions */

ll digsum(ll n){
	ll sum1=0;
	while(n){
		sum1+=n%10;
		n/=10;
	}
return sum1;
}

ll primesum(ll n)
{
	ll sum=0;
	while (n%2 == 0){
		sum+=2;        
		n = n/2;
	}
	for (ll i = 3; i <= sqrt(n); i = i+2)
	{
		while (n%i == 0)
		{
			sum+=digsum(i); 
			n = n/i;
		}
	}
	if (n > 2)sum+=digsum(n);
	return sum;
}
/*main code*/
int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	 ll n;
	cin>>n;
	ll sum1,sum2;
	sum2=primesum(n);
	sum1=digsum(n);
	sum1=0;
	while(n){
		sum1+=n%10;
		n/=10;
	}
	cout<<(sum1==sum2)<<endl;
	//exectime();
	return 0;
}
