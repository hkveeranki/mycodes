#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	double h,u,d,f,k;
	double i=0,ans=0;
	cin>>h>>u>>d>>f;
	while(h!=0){
		i=ans=0;
		k=u;
		while(1){
			ans++;
			i+=k;
			if(i>h){
				cout<<"success on day "<<ans<<endl;
				break;
			}
			i-=d;
			if(i<0){
				cout<<"failure on day "<<ans<<endl;
				break;
			}
			k-=(u*f)/100;
			if(k<0)k=0;
		}
		cin>>h>>u>>d>>f;
	}
	return 0;
}
