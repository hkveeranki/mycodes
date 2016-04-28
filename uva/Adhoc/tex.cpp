#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
int c,state=0;
while((c=getchar())!=EOF){
if(state==0 && c=='"'){
	state=1;
	putchar('`');
	putchar('`');
}
else if(state==1 && c=='"'){
	state=0;
	putchar('\'');
	putchar('\'');

}
else putchar(c);
}
return 0;
}
