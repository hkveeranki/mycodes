#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char s[51];
	while(1){
		cin>>s;
		if(s[0]=='#')return 0;
	if(next_permutation(s,s+strlen(s)))
		cout<<s<<endl;
	else cout<<"No Successor"<<endl;
	}
}
