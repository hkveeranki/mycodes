#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[200005],val[2000006];
bool vis[2000006]={0};
int main()
{
	int n,i,j,ans=0,maxm=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		vis[a[i]]=1;
	}
	sort(a,a+n);
	for(i=1;i<=2000000;i++)
		if(vis[i])val[i]=i;
		else val[i]=val[i-1];
	for(i=0;i<=1000000;i++){
		if(vis[i]){
			for(j=2*i-1;j<=2000000;j+=i){
				ans=max(ans,val[j]%i);
			}
		}
	}
	cout<<ans<<endl;
}
