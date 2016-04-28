#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
long long a[100005];
int main()
{
	int n,i;
	long long ans=0,end=0;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	end=a[0];ans=1;
	for(i=1;i<n;i++) 
		if(a[i]>=end)
			end+=a[i],ans++;
	cout<<ans<<endl;
}
