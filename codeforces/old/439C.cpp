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
vector<VI> ans;
VI odd;
VI even;
const int maxsize=1e5+1;
int a[maxsize];
/*main code*/
int main()
{
	//std::ios::sync_with_stdio(false);
	///cin.tie(NULL);
	int n,k,p,i,j,oddreq,evenreq;
	bool fl=true;
	cin>>n>>k>>p;
	rep(i,0,n-1){
		cin>>a[i];
		if(a[i]%2==1)odd.PB(a[i]);
		else even.PB(a[i]);
	}
	oddreq=k-p;
	evenreq=p;
	if(odd.size() % 2 != oddreq % 2||odd.size()<oddreq)fl=false;
	else{
		if(even.size()+(odd.size()-oddreq)/2 < evenreq) fl=false;
		else{	
			VI tmp1;
			rep(i,0,oddreq-1){
				cout<<endl;
				cout<<endl;
				tmp1.PB(odd[odd.size()-1]);
				odd.pop_back();
				ans.PB(tmp1);
				tmp1.clear();
			}
			while(odd.size()>=2){
				VI temp;
				temp.PB(odd[odd.size()-1]);
				odd.pop_back();
				temp.PB(odd[odd.size()-1]);
				odd.pop_back();
				ans.PB(temp);
				evenreq--;
			}
		for(j=0;j<even.size();j++){
				tmp1.PB(even[j]);
				ans.PB(tmp1);
				tmp1.clear();
			}
		}
	}
	if(!fl)cout<<"NO\n";
	else {
		cout<<"YES\n";
		VI fin;
		assert(ans.size()>=k);
		rep(i,k-1,ans.size()-1) rep(j,0,ans[i].size()-1)fin.PB(ans[i][j]);
		rep(i,0,k-2){
			cout<<ans[i].size()<<" ";
			rep(j,0,ans[i].size()-1){
				if(j!=ans[i].size()-1)
					cout<<ans[i][j]<<" ";
				else cout<<ans[i][j]<<endl;
			}
		}
		cout<<fin.size()<<" ";
		rep(j,0,fin.size()-1){
			if(j!=fin.size()-1) cout<<fin[j]<<" ";
			else cout<<fin[j]<<endl;
		}
	}
	return 0;
}
