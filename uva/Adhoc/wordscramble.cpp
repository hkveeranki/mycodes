#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	int i,j,size,len;
	while(getline(cin,s)){
		size=s.size();
		for(i=0;i<size;i++){
		len=0;
			if(s[i]==' ')cout<<s[i];
			else{
				while(s[i+len]!=' ' && i+len<size)len++;
				for(j=i+len-1;j>=i;j--)cout<<s[j];
				i+=len-1;
			}
		}
		cout<<endl;
	}
	return 0;
}
