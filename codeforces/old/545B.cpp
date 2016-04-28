#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	bool vis[100005];
	int cnt=0,i,j,k,fl;
	memset(vis,0,sizeof(vis));
	for(i=0;i<s1.length();i++)
		if(s1[i]!=s2[i]){
			vis[i]=1;
			cnt++;
		}
	if(cnt%2==1)cout<<"impossible\n";
	else{
		fl=0;
		for(i=0;i<s1.length();i++){
			if(vis[i]==0)
				cout<<s1[i];
			else{
				if(fl==0)cout<<(1-(s1[i]-'0'));
				else cout<<s1[i]-'0';
				fl=1-fl;
			}
		}
		cout<<endl;
	}
	return 0;
}
