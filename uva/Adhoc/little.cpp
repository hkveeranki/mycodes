#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int num,ans;
	while(scanf("%d",&num)!=EOF){
		unsigned p=(unsigned)num;
		unsigned b1,b2,b3,b0;
		b0 = (num & 0x000000ff) << 24u;
		b1 = (num & 0x0000ff00) << 8u;
		b2 = (num & 0x00ff0000) >> 8u;
		b3 = (num & 0xff000000) >> 24u;
		ans=b0|b1|b2|b3;
		cout<<num<<" converts to "<<(int)ans<<endl;
	}
}
