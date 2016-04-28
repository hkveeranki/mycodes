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

struct trie{
struct trie *a[27];
bool mark;
};
/*Functions */


/*main code*/
int main()
{
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	trie *head=(trie*)malloc(sizeof(trie));
	head->mark=0;
	ll i,j,n,k,ans=0,cnt,l;
	for(l=0;l<27;l++)head->a[l]=NULL;
	char bad[27],s[1501];
	trie *temp=head;
	scanf("%s%s%lld",s,bad,&k);
	n=strlen(s)-1;
	rep(i,0,n){
		temp=head;
		cnt=0;
		rep(j,i,n){
			if(bad[s[j]-'a']=='0')cnt++;
			if(cnt==k+1)break;
			if(temp->a[s[j]-'a']==NULL){
				temp->a[s[j]-'a']=(trie *)malloc(sizeof(trie));
				temp->a[s[j]-'a']->mark=0;
				for(l=0;l<27;l++)temp->a[s[j]-'a']->a[l]=NULL;
			}
			temp=temp->a[s[j]-'a'];
			if(temp->mark==0){
				ans++;
				temp->mark=1;
			}
		}
	}
	cout<<ans<<endl;
	//exectime();
	return 0;
}
