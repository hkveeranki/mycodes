#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,ansi,ansj,ans,l;
	while(scanf("%d%d",&i,&j)!=EOF){
		ansi=i;
		ansj=j;
		ans=0;
		if(i>j){
			i=i+j;
			j=i-j;
			i=i-j;
		}
		unsigned n;
		while(i<=j){
			n=i;
			l=1;
			while(n!=1){
				if(n&01){
					unsigned p=n<<2;
					p-=n;
					p+=1;
					n=p;
				}
				else n>>=1;
				l++;
			}
			i++;
			ans=max(l,ans);
		}
		cout<<ansi<<" "<<ansj<<" "<<ans<<endl;
	}
	return 0;
}
