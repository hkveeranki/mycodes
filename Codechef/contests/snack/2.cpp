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


ll A[1000];
ll voted[1000];

int main()
{
	std::ios_base::sync_with_stdio(false);
	ll a,b,c,i,j,k,n,m;
	TC(){
		bool flag=0;
		cin >> n;
		for(j=0;j<1000;j++)
		{
			A[j]=0;
			voted[j]=-1;
		}
		for(j=0;j<n;j++)
		{
			cin >> A[j];
			if(A[j]>=n)
				flag=1;
		}
		ll sum=0;
		for(j=0;j<n;j++)
			sum+=A[j];
		if(sum!=n)
			flag=1;
		if(flag==1)
			cout << -1 << endl;
		else
		{
			ll flag=0,cnt=0,j=0;
			for(j=0;j<n;j++)
			{
				ll max=0,pos=0;
				for(k=0;k<n;k++)
				{
					if(k!=j && A[k]>=max)
					{
						max=A[k];
						pos=k;
					}
				}
				A[pos]--;
				voted[j]=pos;
			}
			for(j=0;j<n;j++)
			{
				if(j!=n-1)
					cout << voted[j]+1 << " ";
				else
					cout << voted[j]+1 << endl;
			}
		}
	}
	return 0;
}

