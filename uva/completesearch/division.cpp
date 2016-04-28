#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool check(int m,int n){
	int a[10]={0},i;
	i=0;
	while(m){
		a[m%10]++;
		m/=10;
		i++;
	}
	if(i<5)a[0]++;
	i=0;
	while(n){
		a[n%10]++;
		n/=10;
		i++;
	}
	if(i<5)a[0]++;
	for(i=0;i<10;i++)if(a[i]!=1)return false;
	return true;
}
int main()
{
	int n,i,j,count=0,cnt=0;
	cin>>n;
	while(n!=0){
		count=0;
		if(cnt)cout<<endl;
		cnt++;
	for(i=1234;i<=98765;i++){
		j=i*n;
		if(check(i,j)){
			count++;
			printf("%05d / %05d = %d\n",j,i,n);
		}
	}
	if(count==0)cout<<"There are no solutions for "<<n<<".\n";
	cin>>n;
	}
}
