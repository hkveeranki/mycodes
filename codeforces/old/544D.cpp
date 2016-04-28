/*Hemanth Kumar */

/*header files*/

#include<bits/stdc++.h>

using namespace std;

/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()

/*standard values*/

#define INF 1e18
#define PI 3.14
#define MAX 200009

/*Frequent functions*/

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar


/*loops and initialisation*/
#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)

/*typedef's for frequently used*/

typedef long long int ll;
typedef vector<int>VI;
typedef vector<ll>VLI;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
typedef unsigned long long int ull;

/*space for global variables*/
typedef struct node{
	long long int val;
	long long int weight;
	struct node *next;
}node;
node* a[MAX];
long long int heap[MAX],dis[MAX],size=0,pos[MAX],par[MAX],ans[MAX];
bool vis[MAX];
void shuffleup(long long int pos1){
	long long int i=pos1,temp,p;
	while(i>1){
		p=i/2;
		if(dis[heap[p]]>dis[heap[i]]){
			temp=pos[heap[i]];
			pos[heap[i]]=pos[heap[p]];
			pos[heap[p]]=temp;
			temp=heap[i];
			heap[i]=heap[p];
			heap[p]=temp;
			i=p;
		}
		else break;
	}
}
void insert(long long int value){
	heap[++size]=value;
	pos[value]=size;
	shuffleup(size);
}
void shuffledown(long long int pos1){
	long long int i=pos1,temp,p;
	while(i<=size/2 && (dis[heap[i]]>dis[heap[2*i]]|| dis[heap[i]]>dis[heap[2*i+1]])){
		if(dis[heap[2*i]]<dis[heap[2*i+1]]) p=2*i;
		else p=2*i+1;
		temp=pos[heap[i]];
		pos[heap[i]]=pos[heap[p]];
		pos[heap[p]]=temp;
		temp=heap[i];
		heap[i]=heap[p];
		heap[p]=temp;
		i=p;	
	}
}
long long int deletemin(){
	long long int min=heap[1];
	heap[1]=heap[size--];
	pos[heap[1]]=1;
	shuffledown(1);
	return min;
}
bool mark[3001][3001];
void djik(long long int src,long long int n){
	long long int cur,i,j;
	node *tmp;
	for(i=1;i<=n;i++){
		dis[i]=99999;
		vis[i]=0;
		par[i]=0;
		pos[i]=0;
	}
	dis[src]=0;
	insert(src);
	vis[src]=1;
	while(size!=0){
		cur=deletemin();
		tmp=a[cur];
		while(tmp!=NULL && tmp->val >0 ){
			if(!vis[tmp->val]){
				dis[tmp->val]=dis[cur]+tmp->weight;
				insert(tmp->val);
				par[tmp->val]=cur;
				vis[tmp->val]=1;
			}
			else if(dis[tmp->val]>dis[cur]+tmp->weight){
				dis[tmp->val]=dis[cur]+tmp->weight;
				par[tmp->val]=cur;
				shuffleup(pos[tmp->val]);
			}
			tmp=tmp->next;
		}
	}
}
int main()
{
	long long int n,m,i,x,y,w,s1,t1,l1,s2,t2,l2,j;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++) {
		a[i]=NULL;
		par[i]=0;
		pos[i]=0;
	}
	for(i=0;i<m;i++){
		scanf("%lld%lld",&x,&y);
		w=1;
		node *p,*q;
		p=(node *)malloc(sizeof(node));
		p->val=x;
		p->weight=w;
		p->next=a[y];
		a[y]=p;
		q=(node *)malloc(sizeof(node));
		q->val=y;
		q->weight=w;
		q->next=a[x];
		a[x]=q;
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)mark[i][j]=0;
	scanf("%lld%lld%lld",&s1,&t1,&l1);
	scanf("%lld%lld%lld",&s2,&t2,&l2);
	djik(s1,n);
	if(!vis[t1]||dis[t1]>l1)printf("-1\n");
	else{
		w=-1;
		i=t1;
		while(i!=0){
			ans[++w]=i;
			i=par[i];
		}
			cout<<"For1\n";
			show(i,ans,w);
		for(i=0;i<w-1;i++){
			mark[ans[i]][ans[i+1]]=1;
		}
		djik(s2,n);
		if(!vis[t2]||dis[t2]>l2)printf("-1\n");
		else{
			w=-1;
			i=t2;
			while(i!=0){
				ans[++w]=i;
				i=par[i];
			}
			cout<<"For2\n";
			show(i,ans,w);
			for(i=0;i<w-1;i++){
				mark[ans[i]][ans[i+1]]=1;
			}
			int cnt=0;
			for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(mark[i][j])cnt++;
			printf("%lld\n",m-cnt);
		}
	}
	return 0;
}
