/*Author: harry7*/

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

struct trie{
	int cnt,cnt1;
	struct trie* a[2];
};
int s[16],len;

/*Functions */

void f(int n){
	if(n==0){
	s[0]=0;
	len=1;
	return ;
	}
	int i=0;
	while(n){
		s[i++]=n%2;
		n/=2;
	}
	len=i;

}
void add(trie* head,int index){
	if(index==len)return ;
	int i=s[index];
	if(head->a[i]==NULL){
	//cout << "Added " << s[index] << endl;
		head->a[i]=(trie*)malloc(sizeof(trie));
		head->a[i]->cnt=0;
		head->a[i]->cnt1=0;
	}
	head->cnt1++;
	if(index+1==len){
		//cout << "Counted added for " << s[index] << endl;
		head->cnt++;
	}
	else add(head->a[i],index+1);
}
void del(trie* head,int index,int val1){
	//out4(s[index],index,val1,len);
if(head==NULL)return ;	
	if(index+1==len){
		//cout << "\nEntered\n";
		head->cnt--;
		head->cnt1--;
		//cout << val1 << "'s pointer\n";
		if(head->cnt1<=0)head=NULL;
		return ;
	}
	del(head->a[s[index]],index+1,s[index]);
	if(head->cnt1>0)head->cnt1--;
	else head=NULL;
	return ;
}
int fcnt(trie* head,int index,int val1){
	if(index==len)return 0;
	//cout << "Called for " ;
	//out3(s[index],index,val1);
	if(head==NULL)return 0;
	int val=fcnt(head->a[s[index]],index+1,s[index]);
	if(s[index]==1)val+=fcnt(head->a[0],index+1,0);
	return head->cnt+val;
}

/*main code*/

int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
		trie* head=(trie*)malloc(sizeof(trie));
		head->cnt=0;
		head->a[0]=head->a[1]=NULL;
	TC(){
		string q;
		int  n;
		cin >> q >> n;
		f(n);
		if(q=="add")add(head,0);
		else if(q=="del")del(head,0,-1);
		else cout << fcnt(head,0,-1) << endl;
	}
	//exectime();
	return 0;
}
