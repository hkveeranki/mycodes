#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
class myfunc{
	bool operator() (int a,int b){return a<b;}
};
int main()
{
	priority_queue<int,myfunc> q;
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;;i++){
		cin>>j;
		q.push(j);
	}
	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}
