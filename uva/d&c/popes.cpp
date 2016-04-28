//Can do it with binary search .. How??
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int years[1000006],n,y;
void solve(){
	int i,cnt,j,ans=-1,anss,anse;
	for(i=0;i<n;i++){
		cnt=1;
		j=i+1;
		while(j<n&& years[j]<years[i]+y){cnt++;j++;}
		if(cnt>ans){
			ans=cnt;
			anss=years[i];
			anse=years[j-1];
		}
	}
	cout<<ans<<" "<<anss<<" "<<anse<<endl;
}
int main()
{
	while(scanf("%d",&y)!=EOF){
		cin>>n;
		int i,j;
		for(i=0;i<n;i++)cin>>years[i];
		solve();
	}
	return 0;
}
