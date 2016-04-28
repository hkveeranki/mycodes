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

ll ft[100005],N;

/*Functions */

void update(ll p,ll  v){
	for (; p <= N; p += p&(-p))
		ft[p] += v;
}
void rupdate(ll a,ll b,ll v){
	update(a, v) ;    
	update(b + 1, -v) ; 	 
}
ll query(ll b){     
	ll	sum = 0;     
	for(; b > 0; b -= b&(-b))
		sum += ft[b];
	return sum;
}
/*main code*/
int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int m,i,j;
	ll x;
	cin>>N>>m;
	rep(i,1,N){
		cin>>x;
		rupdate(1,i,x);
		if(i!=1) rupdate(1,i-1,-x);
	}
	while(m--){
		cin>>j;
		if(j==1){
			cin>>i>>x;
			x-=query(i);
			rupdate(1,i,x);
			if(i!=1) rupdate(1,i-1,-x);
		}
		else if(j==2){
			cin>>x;
			rupdate(1,N,x);
		}
		else{
			cin>>x;
			cout<<query(x)<<endl;
		}
	}
	//exectime();
	return 0;
}
