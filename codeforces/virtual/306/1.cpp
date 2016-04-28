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

bool vis[100005];

/*Functions */



/*main code*/
int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	string s;
	init(vis,false);
	int i,n,fl=0;
	cin>>s;
	n=s.length();
	rep(i,0,n-2){
		if(s[i]=='A' && s[i+1]=='B'){
			vis[i+1]=vis[i]=true;
			fl=1;
			break;
		}
	}
	if(fl==1){
		rep(i,0,n-2){
			if(!vis[i] && s[i]=='B' && !vis[i+1] && s[i+1]=='A'){fl=2;break;}
		}
	}
	if(fl==2)cout<<"YES\n";
	else {
		init(vis,false);
		fl=0;
		rep(i,0,n-2){
			if(s[i]=='B' && s[i+1]=='A'){
				vis[i+1]=vis[i]=true;
				fl=1;
				break;
			}
		}
		if(fl==1){
			rep(i,0,n-2){
				if(!vis[i] && s[i]=='A' && !vis[i+1] && s[i+1]=='B'){fl=2;break;}
			}
		}
		if(fl==2)cout<<"YES\n";
		else cout<<"NO\n";
	}
	//exectime();
	return 0;
}
