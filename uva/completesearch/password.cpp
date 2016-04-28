#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,len;
string words[101],rule;
string digits[10]={"0","1","2","3","4","5","6","7","8","9"};
void solve(int pos,string str){
	if (pos>=len){
		cout<<str<<endl;
		return;
	}
	int i;
	if(rule[pos]=='#'){
	for(i=0;i<n;i++){
	solve(pos+1,str+words[i]);
	}
	}
	else if(rule[pos]=='0'){
	for(i=0;i<10;i++)solve(pos+1,str+digits[i]);
	}
}
int main()
{
	int m,i,j;
	while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++)cin>>words[i];
	cin>>m;
	string str="";
	for(i=0;i<m;i++){
		cin>>rule;
		len=rule.length();
		cout<<"--\n";
		solve(0,str);
	}
	}
	return 0;
}
