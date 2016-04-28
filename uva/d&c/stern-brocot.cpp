#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	double n,m,n1,m1,m2,n2,mp,np;
	while(1){
		cin>>m>>n;
		if(n==1 && m==1)return 0;
		m1=0;
		n1=1;
		m2=1;
		n2=0;
		while(1){
			mp=m1+m2;
			np=n1+n2;
			if(mp==m && np==n)break;
			if(mp/np>m/n){
				cout<<"L";
				n2=np;
				m2=mp;
			}
			else{
				cout<<"R";
				n1=np;
				m1=mp;
			}
		}
		cout<<endl;
	}
	return 0;
}
