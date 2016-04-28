#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long int C[2001][2001];
long long int com(int n, int k){
	int i, j;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= min(i, k); j++)
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = (C[i-1][j-1]%1000000007 + C[i-1][j]%1000000007)%1000000007;
	return C[n][k];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;	
		cin>>n>>m;
		m--;
		k=fmin(n,m);
		cout<<com(n+m,k)%1000000007<<endl;
	}
}
