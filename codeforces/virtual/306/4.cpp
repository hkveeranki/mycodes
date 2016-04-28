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


/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int k,i,j,s;
	cin>>k;
	if(k%2==0){
		cout<<"NO";
		return 0;
	}
	if(k==1){
		cout<<"YES\n2 1\n1 2";
		return 0;
	}
	cout<<"YES\n";
	cout<<(2*k+4)<<" "<<k*(k+2)<<endl;
	cout<<1<<" "<<k+3<<endl;
	for (int l=0;l<2;l++){
		if(l==0)i=1;
		else i=k+3;
		rep(j,3,k+1){
			cout<<i<<" "<<j+i<<endl;
			cout<<j+i<<" "<<i+1<<endl;
			cout<<j+i<<" "<<i+2<<endl;
		}
		rep(j,0,k-2) rep(s,j+1,k-2) if(!(j%2==0 && j+1==s)) cout<<i+3+j<<" "<<i+3+s<<endl;	
		cout<<i+1<<" "<<i+2<<endl;
	}
	//exectime();
	return 0;
}
