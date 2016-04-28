#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct trie{
	struct trie *a[27];
	bool mark;
}trie;
int main()
{
	trie *head=(trie*)malloc(sizeof(trie));
	head->mark=0;
	long long int i,j,n,k,ans=0,cnt,l;
	for(l=0;l<27;l++)head->a[l]=NULL;
	char bad[27],s[1501];
	trie *temp=head;
	scanf("%s%s%lld",s,bad,&k);
	n=strlen(s);
	for(i=0;i<n;i++){
		temp=head;
		cnt=0;
		for(j=i;j<n;j++){
			if(bad[s[j]-'a']=='0')cnt++;
			if(cnt==k+1)break;
			if(temp->a[s[j]-'a']==NULL){
				temp->a[s[j]-'a']=(trie *)malloc(sizeof(trie));
				temp->a[s[j]-'a']->mark=0;
				for(l=0;l<27;l++)temp->a[s[j]-'a']->a[l]=NULL;
			}
			temp=temp->a[s[j]-'a'];
			if(temp->mark==0){
			ans++;
			temp->mark=1;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
