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

int f1,f2,f3,f4;
string s1,s2,s3,s4;

/*Functions */

bool check(){
	for(f1=0;f1<s1.length();f1++)
		for(f2=0;f2<s2.length();f2++)
			if(s1[f1]==s2[f2])goto y;
y:
	for(f3=0;f3<s3.length();f3++)
		for(f4=0;f4<s4.length();f4++)
			if(s3[f3]==s4[f4])goto z;
z:	if(f1==s1.length()||f2==s2.length()||f3==s3.length())return 0;
	return 1;
}

/*main code*/

int main(){
	//FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	int cnt=0;
	while(1){
		cin>>s1;
		if(s1=="#")break;
		if(cnt!=0)cout<<endl;
		cnt++;
		cin>>s2>>s3>>s4;
		if(!check())cout<<"Unable to make two crosses\n";
		else{
			int N,xat,yat,L;
			N=max(s2.length()-f2,s4.length()-f4)+max(f2,f4);
			xat=s1.length()+3+f3;
			if(f2>f4)
			{
				for(int i=0;i<f2-f4;i++)
					s4=" "+s4;
			}
			else
			{
				for(int i=0;i<f4-f2;i++)
					s2=" "+s2;
			}
			if((s2.length()-f2)>(s4.length()-f4))
			{
				L=((s2.length()-f2)-(s4.length()-f4));
				for(int i=0;i<=L;i++)
				{
					s4=s4+" ";
				}
				s4=s4+" ";
			}
			else
			{
				L=((s4.length()-f4)-(s2.length()-f2));
				for(int i=0;i<=L;i++)
				{
					s2=s2+" ";
				}
				s2+=" ";
			}
			yat=max(f2,f4);
			for(int i=0;i<N;i++)
			{
				if(i==yat) cout<<s1<<"   "<<s3;
				else
				{
					if(i>=s2.length())s2.push_back(' ');
					if(i>=s4.length())s4.push_back(' ');

					if(s2[i]!=' ' && s4[i]!=' ')
						printf("%*c%*c",f1+1,s2[i],xat-f1,s4[i]);
					else if(s2[i]==' ')
						printf("%*c",xat+1,s4[i]);
					else
						printf("%*c",f1+1,s2[i]);

				}
				cout<<endl;
			}

		}
	}
	//exectime();
	return 0;
}
