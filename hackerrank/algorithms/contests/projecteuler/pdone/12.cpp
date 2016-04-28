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


/*main code*/
int main()
{
	long long int arr[1001],t,k=2;
	arr[1]=3;
	long long int n,count=0,count1=0;
	long long int i,s,j;
	long long int p;
	for(i=3;i<41041;i++)
	{
		s=(i*(i+1))/2;
		count1=count=0;
		if(i%2==0)
		{
			p=i/2;
			for(j=1;j*j<p;j++)
			{
				if(p%j==0)
					count+=2;
			}
			if(j*j==p)
				count++;
			for(j=1;j*j<(i+1);j++)
				if((i+1)%j==0)
					count1+=2;
			if(j*j==(i+1))
				count1++;
		}
		else
		{
			p=(i+1)/2;
			for(j=1;j*j<p;j++)
			{
				if(p%j==0)
				{
					count+=2;
				}
			}
			if(j*j==p)
				count++;
			for(j=1;j*j<i;j++)
				if(i%j==0)
					count1+=2;
			if(j*j==i)
				count1++;
		}
		long long int l = (count*count1);
//		printf("s= %lld i=%lld i+1 = %lld count= %lld count1 = %lld l=%lld\n",s,i,i+1,count,count1,l);
		if(l>k)
		{
			for(j=k;j<fmin(l,1001);j++)
				arr[j]=s;
			k=l;
		}
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",arr[n]);
	}
	return 0;
}

