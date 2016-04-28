#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int f,r;
	cin>>f;
	while(1){
		if(f==0)return 0;
		cin>>r;
		float a[101],b[101],d[100001],ans=-1;
		int i,j,k,l;
		for(i=0;i<f;i++)cin>>a[i];
		for(i=0;i<r;i++)cin>>b[i];
		for(j=0,k=0;j<r;j++)for(i=0;i<f;i++)d[k++]=b[j]/a[i];
		sort(d,d+k);
		for(i=0;i<k-1;i++)if(d[i]!=d[i+1])ans=max(ans,d[i+1]/d[i]);
		printf("%0.2f\n",ans);
		cin>>f;
	}
}
