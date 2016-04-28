#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
long long int pages[502];
bool vis[501];
int m,k;
//binary search + greedy woah!:D
int solve(int M){
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	int pos = m - 1;
	while (pos >= 0)
	{
		long long sum = 0;
		bool ok = true;
		while (pos >= 0 && sum + pages[pos] <= M)
		{
			ok = false;
			sum += pages[pos];
			--pos;
		}
		if (ok)
		{
			return k + 1;
		}
		if (pos >= 0) vis[pos] = true;
		++cnt;
	}
	return cnt;
}
long long searchans(long long min,long long sum)
{
	long long left = min, right = sum, mid;
	while (left < right)
	{
		mid = (left + right) >> 1;
		if (solve(mid) <= k)
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}
void output(int ans){
	int cnt = solve(ans);
	for (int i = 0; i < m - 1 && cnt < k; ++i)if (!vis[i])
	{
		vis[i] = true;
		++cnt;
	}
	for (int i = 0; i < m; ++i)
	{
		if (i) cout<<" "<<pages[i];
		else cout<<pages[i];
		if (vis[i])
		{
			cout<<" /";
		}
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		long long  i,j,start,end=0,mid,sum=0,tsum,cnt;
		cin>>m>>k;
		for(i=0;i<m;i++){cin>>pages[i];sum+=pages[i];}
		start=searchans(1,sum);
		output(start);
	}
}
