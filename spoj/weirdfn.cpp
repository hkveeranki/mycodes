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

ll mod=1000000007;

/*Functions */


/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int maxsize,minsize,i;
		ll n,a,b,c;
			ull sum,f;
	TC(){
		cin>>a>>b>>c>>n;
		sum=1;
		ll med;
		priority_queue<ll ,vector<ll>,less<ll> > maxheap;
		priority_queue<ll ,vector<ll>,greater<ll> > minheap;
		maxheap.push(1);
		maxsize=maxheap.size();
		minsize=minheap.size();
		rep(i,2,n){
			med=maxheap.top();
			f=a*med+(unsigned ll)b*i+(unsigned ll)c;
			if(f>=mod)
				f%=mod;
			sum+=f;
			if(f<med){
				maxheap.push(f);
				maxsize++;	
			}
			else
			{
				minheap.push(f);
				minsize++;
			}
			while(maxsize>minsize+1){
				minheap.push(maxheap.top());
				maxheap.pop();
				maxsize--;
				minsize++;
			}
			while(minsize>maxsize){
				maxheap.push(minheap.top());
				minheap.pop();
				minsize--;
				maxsize++;
			}
		}
		cout<<sum<<endl;
	}
	//exectime();
	return 0;
}
