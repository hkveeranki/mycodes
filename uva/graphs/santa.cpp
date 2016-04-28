#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool a[5][5]={0};
int ans[10];
void func(int present,int count){
	ans[count]=present;
	if(count==8){for(int i=0;i<9;i++)cout<<ans[i]+1;cout<<endl;return ;}
	for(int i=0;i<5;i++)
		if(a[present][i]){
		a[present][i]=a[i][present]=0;
		func(i,count+1);
		a[present][i]=a[i][present]=1;
		}
}
int main()
{
	a[0][1]=a[0][4]=a[0][2]=1;
	a[1][0]=a[1][2]=a[1][4]=1;
	a[2][0]=a[2][1]=a[2][3]=a[2][4]=1;
	a[3][2]=a[3][4]=1;
	a[4][0]=a[4][1]=a[4][2]=a[4][3]=1;
func(0,0);
}
