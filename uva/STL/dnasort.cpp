#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct info{
	string s;
	int count1;
};
info a[102];
bool cmp(info a,info b){return a.count1<b.count1;}
int getcount(string   s){
	int i,j,c=0,n=s.length();
	for(i=0;i<n;i++)for(j=i+1;j<n;j++)if(s[i]>s[j])c++;
	return c;
}
int main()
{
	int t,tc;
	cin>>tc;
	for(t=1;t<=tc;t++){
		int n,i,j,l;
		cin>>l>>n;
		for(i=0;i<n;i++){
			cin>>a[i].s;
			a[i].count1=getcount(a[i].s);
		}
		stable_sort(a,a+n,cmp);
		if(t!=1)cout<<endl;
		for(i=0;i<n;i++)cout<<a[i].s<<endl;
	}
}
