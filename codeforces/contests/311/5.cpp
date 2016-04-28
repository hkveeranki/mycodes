/*Author: Hemanth Kumar Veeranki */

/*handle: harry7*/

/*header files*/

#include<bits/stdc++.h>

using namespace std;

/*typedef's for frequently used*/

typedef long long int ll;
typedef vector<int>VI;
typedef vector<ll>VLI;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
typedef unsigned long long int ull;

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

/*For variables*/	

#define LET(a) __typeof(a) x(a) 
#define ALL(a) a.begin(),a.end()

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
#define swap(VAR1,VAR2) VAR1=VAR1^VAR2;VAR2=VAR1^VAR2;VAR1=VAR1^VAR2
#define UB(x,a) (upper_bound(ALL(a),x)-a.begin())
#define LB(a,x) (lower_bound(ALL(a),x)-a.begin())
#define NP(a) next_permutation(ALL(a))

/*exponentiation*/


ll inline ipow(ll a,ll b,ll m){ll val=1;a%=m;while(b){if(b&01)val=(val*a)%m;b>>=1;a=(a*a)%m;};return val%m;}
ll inline ipow(ll a,ll b){ll val=1;while(b){if(b&01)val=(val*a);b>>=1;a=(a*a);};return val;}

/* Seive */


/*
#define LIM1 1000001
bitset<LIM1> isp;
vi primes;
inline void seive(){isp.set();isp.reset(0);isp.reset(1);for(int i=2;i*i<LIM1;i++)if(isp[i]){for(int j=i<<1;j<LIM1;j+=i)isp.reset(j);}repl(i,2,LIM1)if(isp[i]){primes.pb(i);}}
*/

/* Totient */

/*
#define LIM4 1000001
int phi[LIM4];
void totient(){repl(i,1,LIM4)phi[i]=i;tr(primes,it)for(int i=*it;i<LIM4;i+=*it)phi[i]-=phi[i]/(*it);}
*/

/* Inverse Modulo */

/*inline ll invmod(ll a, ll b){return (isp[b])?ipow(a,b-2,b):ipow(a,phi[b]-1,b);}*/

/* Combinatorics */

/*
#define LIM2 1000001
ll fact[LIM2];
inline void Fact(){fact[0]=1;repl(i,1,LIM)fact[i]=(i*fact[i-1])%MOD;}
inline ll inv(ll x,ll mod){return ipow(x,mod-2,mod);}
inline ll comb(ll a, ll b){return ((fact[a]*inv(fact[b],MOD)%MOD)*inv(fact[a-b],MOD))%MOD;}
*/

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define repl(i,a,b) for (i=a;i<b;i++)
#define repil(i,a,b) for (i=a;i>b;i--)
#define tr(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define rtr(v,it) for( LET(it,v.rbegin()) ; it != v.rend() ; it++)
#define TC() int t;cin>>t;while(t--)

/*space for global variables*/
const int MAX=5005;
struct TRIE{
	int cnt,next[2];
	void create(){
		cnt=0;next[0]=next[1]=-1;
	}
};
TRIE trie[MAX*MAX];
bool good[MAX][MAX];
string ans="",s;
int size=0,k;

/*Functions */

void insert(int i,int n){//add the required nodes to trie
	int j,cur=0;
	repl(j,i,n){
		if(trie[cur].next[s[j]-'a']==-1){//checking whether its already present in trie or not
			trie[size].create();
			trie[cur].next[s[j]-'a']=size++;
		}
		cur=trie[cur].next[s[j]-'a'];
		if(good[i][j])trie[cur].cnt++;//keeping track of number of substrings ending at this node

	}

}

void dfs(int i){
	k-=trie[i].cnt;
	if(k<=0){//we have found the answer :D so we can print it and exit :)
		cout<<ans<<endl;
		exit(0);
	}
	if(trie[i].next[0]!=-1){//there is a substring going with a. So we traverse there
		ans+='a';
		dfs(trie[i].next[0]);
		ans.erase(ans.size()-1);
	}
	if(trie[i].next[1]!=-1){//there is a substring going with b. So we traverse there
		ans+='b';
		dfs(trie[i].next[1]);
		ans.erase(ans.size()-1);
	}
}
/*main code*/

int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	cin>>s>>k;
	int i,n,j,k;
	init(good,0);//All initialisations
	trie[0].create();//Initialisations
	size++;//keeps track of nodes in trie
	n=s.length();
	rep(k,1,n){//length of substring
		rep(i,0,n-k){//start of substring
			j=i+k-1;//other end of substring
			if(j-i<=3)good[i][j]=(s[i]==s[j]);
			else good[i][j]=( (s[i]==s[j]) && good[i+2][j-2] );//dp kind of thing to remove O(n) comparsion loop
		}
	}	
	repl(i,0,n)insert(i,n);//inserting all the things to trie
	dfs(0);//searching for answer
	//exectime();
	return 0;
}
