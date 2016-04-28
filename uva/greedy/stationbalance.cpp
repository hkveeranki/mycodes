/*Hemanth Kumar */

/*header files*/

#include<bits/stdc++.h>
#include<math.h>
using namespace std;

/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;

/*standard values*/

#define INF 1e18
#define PI 3.14
#define MAX 1000006

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define tc()int t;cin>>t;while(t--)

/*typedef's for frequently used*/

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VLI;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
typedef pair<double,double> dpair;
typedef unsigned long long int ull;

/*space for global variables*/
int a[11];
/*main code*/
int main()
{
	int c,s,s1,cnt=0;
	while(scanf("%d%d",&c,&s)!=EOF){
		cnt++;
		s1=2*c;
		double avg=0,imb=0;
		int i,j,k;
		rep(i,0,s-1){
			cin>>a[i];
			avg+=a[i];
		}
		avg/=c;
		cout<<"Set #"<<cnt<<endl;
		sort(a,a+s);
		int start=s,end=s-s1;
		//show(i,a,s);
		rep(i,0,c-1){
			cout<<" "<<i<<":";
			double sum=0;
			if(end>=0){
				sum+=a[end];
				cout<<" "<<a[end];
			}
			if(start>0){
				sum+=a[start-1];
				cout<<" "<<a[start-1];
			}
			imb+=abs(avg-sum);
			start--;
			end++;
			cout<<endl;
		}
		cout<<"IMBALANCE = "<<setprecision(5)<<fixed<<imb<<endl<<endl;
	}	
	return 0;
}
