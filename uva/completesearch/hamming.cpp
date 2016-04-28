#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	bool a[17];
	int t;
	cin>>t;
	while(t--){
		int n,m,i;
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(i=n-1;i>n-m-1;i--)a[i]=1;
		for(i=0;i<n;i++)cout<<a[i];cout<<endl;
		while(next_permutation(a,a+n)){
			for(i=0;i<n;i++)cout<<a[i];cout<<endl;
		}
		if(t)cout<<endl;
	}
}
