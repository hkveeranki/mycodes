#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[300005];
int main()
{
	int n,i,x,y,ans;
	scanf("%lld",&n);
	for(i=0;i<=n;i++)a[i]=0;
	for(i=0;i<n;i++){
	scanf("%lld%lld",&x,&y);
	a[x]++;
	if(y+1<=n)
	a[y+1]--;
	}
	for(i=1;i<=n;i++)a[i]+=a[i-1];
	for(i=1;i<=n;i++){
	if(a[i]<i)a[i]=0;
	else ans=max(a[i],ans);
	}
	printf("%lld\n",ans);
return 0;
}
