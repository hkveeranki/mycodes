#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int n,m,i,j,k;
	string s;
	cin>>n>>m;
	int a[n+1][10];
	int b[n+1];
	int size[n+1],d[n+1],l[n+1][10],u[n+1][10],c[n+1][10];
	map<string,int>mymap;
	for(i=1;i<=n;i++){
		cin>>s>>b[i]>>size[i]>>d[i];
		mymap[s]=i;
		for(j=1;j<=d[i];j++)cin>>l[i][j]>>u[i][j];
		c[i][d[i]]=size[i];
		for(j=d[i]-1;j>=1;j--)c[i][j]=c[i][j+1]*(u[i][j+1]-l[i][j+1]+1);
	}
	for(j=1;j<=m;j++){
		cin>>s;
		cout<<s<<"[";
		int max=mymap[s];
		int ans=b[max];
		for(k=1;k<=d[max];k++)ans-=c[max][k]*l[max][k];
		for(k=1;k<=d[max];k++){
			cin>>i;
			cout<<i;
			if(k!=d[max])cout<<", ";
			ans+=i*c[max][k];
		}
		cout<<"] = "<<ans<<endl;
	}
	return 0;
}
