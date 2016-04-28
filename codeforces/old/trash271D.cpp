#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int i,n,cnt=1,cnt1=0,ans=0,j,k;
	string s,bad,s1;
	set<string>m;
	cin>>s>>bad>>k;
	n=s.length();
	for(i=0;i<n;i++){
		cnt1=0;
		for(j=i;j<n;j++)
		{
			s1+=s[j];
			if(bad[s[j]-'a']=='0')cnt1++;
			if(cnt1==k+1) break;
			m.insert(s1);
		}
		s1.clear();
	}
	cout<<m.size()<<endl;
}
