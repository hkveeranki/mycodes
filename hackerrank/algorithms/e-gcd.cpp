#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
long long int egcd(long long int a,long long int n)
{
	long long int t,r,t1,r1,q,T,R;
	t=0;t1=1;r=n;r1=a;
	while(r1!=0)
	{
		T=t1;
		R=r1;
		q=(r/r1);
		t1=(t-q*t1);
		r1=(r-q*r1);
		t=T;
		r=R;
	}
	if(t<0)
		t+=n;
	return t;
}
long long int ipow(int x,int n,int z)
{
	long long int res=1;
	long long int bas=x;
	while(n)
	{
		if(n&1)
			res =((res%z)*(bas%z))%z;
		bas=((bas%z)*(bas%z))%z;
		n>>=1;
	}
	return res;
}
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int a,b,x;
		long long int l;
		cin>>a>>b>>x;
		if(b<0)
		{
			l=ipow(egcd(a,x),-b,x);
		}
		else
			l=(ipow(a,b,x))%x;
		cout<<l<<endl;
	}
}
