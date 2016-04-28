#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef pair<string,int> mypair;
bool cmp(mypair a,mypair b){
	if(a.second==b.second)return a.first<b.first;
	return a.second>b.second;
}
int main(){
	string s;
	int count1=1;
	map<string,int>m;
	vector<mypair>v;
	while(getline(cin,s)){
		if(s[0]=='0')return 0;
		if(s[0]=='1')continue;
		count1=1;
		v.clear();
		m.clear();
		v.push_back(make_pair(s,0));
		while(getline(cin,s)){
			if(s[0]=='1'){
				sort(v.begin(),v.end(),cmp);
				for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;
				break;
			}
			if (s[0]>='A' &&s[0]<='Z') {
				v.push_back(make_pair(s,0));
				count1++;
			}
			else{
				if(m[s]==0){
					m[s]=count1;
					v[count1-1].second++;
				}
				else if(m[s]>0 && m[s]!=count1){
					v[m[s]-1].second--;
					m[s]=-1;
				}
			}
		}
	}
}
