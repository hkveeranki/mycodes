#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s[5001];
int cnt[5001][5001];
int c[5001],b[5001];
//one of the extraordinary questions i have seen :D
void sort1(int a[],int n,int m){
	int i;
	//	cout<<n<<"  "<<m<<endl;
	//	cout<<"\nPrinting arrays\n";
	//	for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
	for(i=0;i<=m;i++)
		c[i]=0;
	for(i=0;i<n;i++)c[a[i]]++;
	for(i=1;i<=m;i++)c[i]+=c[i-1];
	for(i=n-1;i>=0;i--){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	for(i=0;i<n;i++)a[i]=b[i];
	//	cout<<"\nPrinting sorted arrays\n";
	///	for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,m,ans=0,j;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>s[i];
	for(i=0;i<n;i++)if(s[i][m-1]=='1'){
		cnt[m-1][i]=1;
		//cout<<i<<endl;
	}
	for(i=m-2;i>=0;i--)
		for(j=0;j<n;j++){
			//cout<<j<<" "<<i<<" "<<s[j][i]<<endl;
			if(s[j][i+1]=='1')
				cnt[i][j]=cnt[i+1][j];
			else cnt[i][j]=0;
			if(s[j][i]=='1'){
				cnt[i][j]++;
			}
			else cnt[i][j]=0;
		}
	//for(j=0;j<n;j++){for(i=0;i<m;i++)cout<<cnt[i][j]<<" ";cout<<endl;}
	//cout<<"End"<<endl;
	for(i=0;i<m;i++){
		sort1(cnt[i],n,m);
		for(j=0;j<n;j++){
			//cout<<i<<" "<<n-j<<" "<<cnt[i][j]<<endl;
			ans=max(cnt[i][j]*(n-j),ans);
		}
	}
	cout<<ans<<endl;
}
