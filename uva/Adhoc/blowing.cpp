#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,k,n,m,cmax,pmax,p,count=0;
	int c[21];
	cin>>n>>m>>cmax;
	while(!(n==0 && m==0 && cmax==0)){
		count++;
	for(i=1;i<=n;i++)cin>>c[i];
	p=pmax=0;
	bool v[21]={0},state=0;
	for(j=1;j<=m;j++){
		cin>>k;
		if(v[k]){
		v[k]=0;
		p-=c[k];
		}
		else{
		v[k]=1;
		p+=c[k];
		}
		pmax=max(p,pmax);
		if(pmax>cmax)state=1;
	}
	cout<<"Sequence "<<count<<endl;
		if(pmax>cmax)state=1;
		if(state)cout<<"Fuse was blown.\n";
		else cout<<"Fuse was not blown.\nMaximal power consumption was " <<pmax<<" amperes.\n";
		cout<<endl;
	cin>>n>>m>>cmax;
	}
}
