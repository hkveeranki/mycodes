//for for good use of stl functions 
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,q,ans1,ans2,h,a[1000006],b[1000006];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		b[n-i-1]=-a[i];
	}
	cin>>q;
	for(i=0;i<q;i++){
		cin>>h;
		ans1=upper_bound(a,a+n,h)-a;
		ans2=upper_bound(b,b+n,-h)-b;
		if(ans2==n)cout<<"X ";
		else cout<<-b[ans2]<<" ";
		if(ans1==n)cout<<"X\n";
		else cout<<a[ans1]<<endl;
	}
}
