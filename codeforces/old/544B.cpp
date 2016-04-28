#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char s[101][101];
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if((i+j)%2==0 && m>0){
				s[i][j]='L';
				m--;
			}
			else s[i][j]='S';
	if(m!=0)cout<<"NO\n";
	else {
		cout<<"YES\n";
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)cout<<s[i][j];
			cout<<endl;
		}
	}
}
