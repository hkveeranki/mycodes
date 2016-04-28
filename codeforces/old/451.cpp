#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
string s;
cin>>s;
long long n,i,anse=0,anso=0;
long long counte[2]={0};
long long counto[2]={0};
n=s.length();
for(i=0;i<n;i++){
anso++;
long long j=s[i]-'a';
if(i&01){
anso+=counto[j];
anse+=counte[j];
counto[j]++;
}
else{
anso+=counte[j];
anse+=counto[j];
counte[j]++;
}
}
cout<<anse<<" "<<anso<<endl;
}
