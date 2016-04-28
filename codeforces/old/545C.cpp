#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
long long int x[100005],h[100005];
bool fell[100005];
int main()
{
	int i,ans=0,n;
	memset(fell,0,sizeof(fell));
	cin>>n;
	for(i=0;i<n;i++)cin>>x[i]>>h[i];
	if(n>=2)ans=2;
	else if(n==1)ans=1;
	for(i=1;i<n-1;i++) 
		if(x[i]-h[i]>x[i-1]) fell[i]=1;
		else if(x[i]+h[i]<x[i+1]){
			fell[i]=1;
			x[i]+=h[i];
		}
	for(i=0;i<n;i++)if(fell[i]==1) ans++;
	cout<<ans<<endl;
	return 0;
}
