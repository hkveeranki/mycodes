#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int maxm,r,c;
int heights[101][101]={0};
void solve(int row,int col,int len){
	if(row<r && row>=0 && col<c && col>=0){
		//cout<<row<<" "<<col<<" "<<heights[row][col]<<endl;
		if(row+1<r && col<c && heights[row][col]>heights[row+1][col])solve(row+1,col,len+1);//below
		if(row-1>=0 && col<c && heights[row][col]>heights[row-1][col])solve(row-1,col,len+1);//above
		if(row<r && col-1>=0 && heights[row][col]>heights[row][col-1])solve(row,col-1,len+1);//left
		if(row<r && col+1<c && heights[row][col]>heights[row][col+1])solve(row,col+1,len+1);//right
	}
	maxm=max(len,maxm);
	return ;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s>>r>>c;
		int i,j;
		for(i=0;i<r;i++)for(j=0;j<c;j++)cin>>heights[i][j];
		maxm=-1;
		for(i=0;i<r;i++)for(j=0;j<c;j++){
			solve(i,j,1);
			//cout<<"Solved\n";
		}
		cout<<s<<": "<<maxm<<endl;
	}
}
