#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 200009
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
		printf("For 1\n");
		for(i=0;i<=w;i++)printf("%lld ",ans[i]);printf("\n");
		for(i=0;i<w;i++){
			mark[ans[i]][ans[i+1]]=1;
			mark[ans[i+1]][ans[i]]=1;
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
		printf("For 2\n");
			for(i=0;i<=w;i++)printf("%lld ",ans[i]);printf("\n");
			for(i=0;i<w;i++){
				mark[ans[i]][ans[i+1]]=1;
				mark[ans[i+1]][ans[i]]=1;
			}
			int cnt=0;
			for(i=1;i<=n;i++){for(j=1;j<=n;j++)printf("%d ",mark[i][j]);printf("\n");}
			for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(mark[i][j])cnt++;
			printf("%lld\n",m-cnt/2);
		}
	}
	return 0;
}
