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

int rank[32],parent[32];

/*Functions */

int par(int i){
	if(parent[i]!=i)parent[i]=par(parent[i]);
	return parent[i];
}
void uni(int x,int y){
	int px=par(x);
	int py=par(y);
	if(px==py)return ;
	if(rank[px]>rank[py])parent[py]=px;
	else if(rank[py]>rank[px])parent[px]=py;
	else{
		parent[py]=px;
		rank[px]++;
	}
}
/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int t;
	scanf("%d\n\n",&t);
	while(t--){
		int i,n,ans=0;
		char x,y,s[5];
		gets(s);
		sscanf(s, "%c", &x);
		n=x-'A'+1;
		rep(i,1,n){
			parent[i]=i;
			rank[i]=0;
		}
		while (gets(s) && strcmp(s, "") != 0) {
			sscanf(s, "%c%c", &x, &y);
			uni(x - 'A'+1, y - 'A'+1);
		}
		rep(i,1,n)if(parent[i]==i)ans++;
		cout<<ans<<endl;
		if(t)cout<<endl;
	}
	//exectime();
	return 0;
}
