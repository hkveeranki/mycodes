#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j=0,t,c,d,count=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for (c = 1 ; c <= n - 1; c++) 
	{
		d = c;
		while ( d > 0 && a[d] < a[d-1]) 
		{
			t         = a[d];
			if(a[d]!=a[d-1])
				count++;
			a[d]   = a[d-1];
			if(a[d-1]!=t)
				count++;
			a[d-1] = t;
			d--;
		}
	}
	cout<<count/2<<endl;
}
