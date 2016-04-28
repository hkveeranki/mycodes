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

stack<ll> st;
VI v;

/*Functions */

ll eval(string s){
	ll tmp = 0,ans,x;
	int i,n=s.length();
	rep(i,0,n-1){
		if (s[i] >= '0' && s[i] <= '9') tmp = tmp * 10 + s[i] - '0';
		if (s[i] == '+' || s[i] == '*' || i == n-1){
			if (st.empty() || st.top() != -1) st.push(tmp);
			else{
				st.pop();
				x = st.top();
				st.pop();
				st.push(tmp * x);
			}
			tmp = 0;

		}
		if (s[i] == '*')
			st.push(-1);
	}
	ans = 0;
	while (!st.empty()){
		ans += st.top();
		st.pop();
	}
	return ans;
}
string toStr(ll x){
	string s = "";
	while (x){
		s += char(x % 10 + '0');
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

/*main code*/

int main(){
	FastIn;
	clock_t tStart = clock();/* for execution time caluclation*/
	string s;
	int i,j,n;
	ll ans,tmp;
	cin >> s;
	n=s.length();
	v.PB(-1);
	rep(i,0,n-1) if (s[i] == '*')v.PB(i);
	v.PB(s.length());
	n=v.size();
	 ans = eval(s);
	rep(i,0,n-1)
		rep(j,i+1,n-1){
			tmp = eval(s.substr(v[i] + 1, v[j] - v[i] - 1));
			ans = max(ans, eval(s.substr(0, v[i] + 1) + toStr(tmp) + s.substr(v[j])));
		}
	cout << ans << endl;	
	//exectime();
	return 0;
}
