#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define MAX 100
int N;
using namespace std;
int pos[MAX],a,b,sc;
bool check(int q,int r){
	for(int i =1;i<=q-1;i++)if(pos[i]==r||abs(pos[i]-r)==abs(q-i))return 0;
	return 1;
}
void solve(int q){
	int r,j;
	for(r=1;r<=N;r++)
		if(check(q,r)){
			pos[q]=r;
			if(q==N){
				sc++;
				printf("%2d      %d",sc,pos[1]);
				for(int i=2;i<=N;i++)cout<<" "<<pos[i];cout<<endl;

			}
			else solve(q+1);
		}
}
int main()
{
	int t;cin>>t;
	while(t--){
		cin>>N;
		memset(pos,0,sizeof(pos));
		cout<<"SOLN       COLUMN\n";
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		sc=0;
		solve(1);
		if(t)cout<<endl;
	}
}
