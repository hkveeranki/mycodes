#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	char s[20];
	map<char,int>mymap;
	mymap['B']=1;
	mymap['P']=1;
	mymap['F']=1;
	mymap['V']=1;
	mymap['C']=2;
	mymap['S']=2;
	mymap['K']=2;
	mymap['G']=2;
	mymap['J']=2;
	mymap['Q']=2;
	mymap['X']=2;
	mymap['Z']=2;
	mymap['D']=3;
	mymap['T']=3;
	mymap['L']=4;
	mymap['M']=5;
	mymap['N']=5;
	mymap['R']=6;
	int i,n,j,k,l;
	for(i=1;i<=9;i++)printf(" ");
	printf("NAME");
	for(i=14;i<=34;i++)printf(" ");
	printf("SOUNDEX CODE\n");
	while(scanf("%s",s)!=EOF){
		char ans[20];
		for(i=1;i<=9;i++)printf(" ");
		printf("%s",s);
		n=strlen(s);
		ans[0]=s[0];
		for(i=1,j=1,l=1;i<n;i++) 
			if(s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U'&&s[i]!='Y'&&s[i]!='W'&&s[i]!='H')
				if(mymap[s[i-1]]!=mymap[s[i]])ans[l++]=mymap[s[i]]+'0';
		for(i=n+10;i<35;i++)printf(" ");
		for(i=0;i<l&&i<4;i++)printf("%c",ans[i]);
		for(;i<4;i++)printf("0");
		printf("\n");
	}
	for(i=1;i<=19;i++)printf(" ");
	printf("END OF OUTPUT\n");
	return 0;
}
