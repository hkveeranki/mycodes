#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
#define MAX 100001
using namespace std;
int n,a[MAX],bit[MAX];
void update(int i,int val){
	while(i<=n){
		bit[i]+=val;
		i+=(i&(-i));
	}
}
int query(int i){
	int sum=0;
	while(i>0){
		sum+=bit[i];
		i-=(i&(-i));
	}
	return sum;
}
int main()
{
	int i,x,y;
	cin>>n;
	for(i=1;i<=n;i++){
		bit[i]=0;
		cin>>a[i];
	}
	for(i=1;i<=n;i++)update(i,a[i]);
	cout<<"Enter two numbers between 1 and n"<<endl;
	cin>>x>>y;
	cout<<"The sum is "<<query(y)-query(x-1)<<endl;
	cout<<"Enter to update Value\n";
	cin>>x>>y;
	update(x,y);
	cout<<"The sum of array is "<<query(n)<<endl;
}
