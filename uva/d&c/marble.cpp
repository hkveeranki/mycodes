#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n,q,cnt=0,a[10004];
	while(1){
		cin>>n>>q;
		if(n==0 && q==0)break;
		cnt++;
		int i,ans,k;
		for(i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		cout<<"CASE# "<<cnt<<":\n";
		for(i=0;i<q;i++){
			cin>>k;
			ans=lower_bound(a,a+n,k)-a;
			if(ans==n||(a[ans]!=k))cout<<k<<" not found\n";
			else cout<<k<<" found at "<<ans+1<<endl;
		}
	}
}
