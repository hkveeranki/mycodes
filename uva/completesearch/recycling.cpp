#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	vector<string>v;
	string s;
	map<char,int>m1;
	map<char,int>m2;
	m1['b'] = 0;
	m1['g'] = 1;
	m1['o'] = 2;
	m1['r'] = 3;
	m1['y'] = 4;
	m2['A'] = 0;
	m2['G'] = 1;
	m2['N'] = 2;
	m2['P'] = 3;
	m2['S'] = 4;
	int mymap[101][5]; 
	while(1){
		cin>>s;
		if(s[0]=='#')return 0;
		if(s[0]=='e')continue;
		v.push_back(s);
		while(1){
			cin>>s;
			if(s[0]=='e')break;
			v.push_back(s);
		}
		int i,j,ans,minm=100001,cnt,k;
		for(i=0;i<v.size();i++)
		{
			j = 0;
			while (j < v[i].length()){
				//cout<<v[i][j]<<" "<<v[i][j+2]<<endl;
				mymap[i][m1[v[i][j]]] = m2[v[i][j+2]];
				j+=4;
			}
		}
		for(i=0;i<v.size();i++){
			cnt=0;
			for(j=0;j<v.size();j++){
				if(i==j)continue;
				for(k=0;k<5;k++)if(mymap[i][k]!=mymap[j][k])cnt++;
			}
			//cout<<i<<" "<<cnt<<endl;
			if(cnt<minm){
				ans=i+1;
				minm=cnt;
			}
		}
		v.clear();
		cout<<ans<<endl;
	}
}
