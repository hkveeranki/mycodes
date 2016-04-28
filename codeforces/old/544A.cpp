#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
vector<string>ans;
map<char,int>m;
int main()
{
	int k,len,prev=0,cnt=0,i;
	cin>>k;
	string s,sub;
	cin>>s;
	int n=s.length();
	m[s[0]]=-1;
	if(k==1)cout<<"YES\n"<<s<<endl;
	else{
		for(i=1;i<n;i++){
			if(cnt==k-1){
				if(m[s[prev]]=0){
					cout<<s[prev]<<endl;
					sub=s.substr(prev,n-prev+1);
					ans.push_back(sub);
					cout<<sub<<" in 2"<<endl;
					cnt++;
					break;
				}
			}
			else if(m[s[i]]==0 && s[i]!=s[prev]){
				cnt++;
				//cout<<i<<" "<<prev<<endl;
				sub=s.substr(prev,i-prev);
				//cout<<sub<<" in 1"<<endl;
				ans.push_back(sub);
				m[s[prev]]=-1;
				prev=i;
			}
		}
		if(cnt==k-1){
			if(m[s[prev]]==0){
				sub=s.substr(prev,n-prev+1);
				ans.push_back(sub);
				//cout<<sub<<" in 3"<<endl;
				cnt++;
			}
		}
		if(cnt!=k)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(i=0;i<ans.size();i++)cout<<ans[i]<<endl;
		}
	}
}
