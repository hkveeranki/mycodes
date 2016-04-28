#include<stdio.h>
#include<math.h>
#define mod 1000000007
#include<iostream>
const int inf=100000000;
using namespace std;
typedef long long int ll;
int size;
int time1=0;
struct x{  int y ;
	ll   a1 , a3 , x , a2  ; // a1 , d - for  operation 1 //
	ll d ;
	int a1t,a2t;
	// a2 - for operation 2 //
};                               // a3 ,  x  - for operation 3 //
struct x lazy[262145];
ll  tree[262145];
int   a[100000];
void create( int i , int b , int c){
	if ( c == b){
		tree[i] =(ll) a[c];
		return ;
	}
	create( 2 * i , b , (b + c)/2 );
	create( (2 * i)+1 , ((b + c)/2 + 1 ) , c );
	tree[i] = ( tree[ (2 * i)] ) + ( tree[ (2 * i) + 1] )%mod;
}
void clear ( int i){
	lazy[i].a1 = 1;
	lazy[i].a2 = 0 ;
	lazy[i].a1t = inf;
	lazy[i].a2t = inf ;
	lazy[i].a3 = 0 ;
	lazy[i].x = 0 ;
	lazy[i].y = 0 ;
	lazy[i].d = 0 ;
}
// THIS IS MADE FOR CHECKING WHETHER NECCESARY UPDATES ARE TO DONE BEFORE NEXT UPDATES//
void propogate( int i , int b , int c){
	if(i>=size)return ;
	if ( lazy[i].y == 0 ){
		return ;
	}
	if  ( lazy[i].a3 == 1){
		tree[i] = ((ll) (c - b + 1)*(lazy[i].x))%mod ;
		if ( b != c){
			lazy[ 2*i].a3 = 1;
			lazy[ 2*i].x= lazy[i].x;
			lazy[ 2*i].y =  1  ;
			lazy[ 2*i + 1].y =  1  ;
			lazy[ 2*i + 1].a3 = lazy[i].a3;
			lazy[2*i + 1].x = lazy[i].x;
			lazy[ 2*i].a3 = 1 ;
			lazy[ 2*i].a1= 1ll;
			lazy[ 2*i].d= 0;
			lazy[ 2*i].a2= 0;
			lazy[2*i + 1].a1 = 1ll;
			lazy[2*i + 1].d = 0;
			lazy[2*i + 1].a2 = 0;

		}
	}
	if(lazy[i].a1t<lazy[i].a2t){
		cout<<"Entered into 1 with b= "<<b<<" and c= "<<c<<endl;
	if ( lazy[i].a1!=1)
	{
		tree[i]=(tree[i]*lazy[i].a1)%mod ;
		if ( b != c)
		{
			lazy[ 2*i + 1].y = 1;
			lazy[ 2*i].y = 1 ;
			lazy[ 2*i + 1].a1t = lazy[i].a1t;
			lazy[ 2*i].a1t = lazy[i].a1t ;
			lazy[ 2*i].a1= (lazy[2*i].a1*lazy[i].a1)%mod ;
			lazy[ 2*i+1].a1= (lazy[2*i+1].a1*lazy[i].a1)%mod ;
		}
	}
	if ( lazy[i].a2!=0)
	{
		tree[i]= (tree[i]+ ( (ll) (c - b + 1)*(lazy[i].a2))%mod)%mod ;
		if ( b != c)
		{
			lazy[ 2*i].y = 1 ;
			lazy[ 2*i].a2= (lazy[2*i].a2+lazy[i].a2)%mod;
			lazy[ 2*i + 1].y = 1  ;
			lazy[ 2*i+1].a2= (lazy[2*i+1].a2+lazy[i].a2)%mod;
			lazy[ 2*i + 1].a2t = lazy[i].a2t;
			lazy[ 2*i].a2t = lazy[i].a2t ;
		}
	}
	}
	else{
		cout<<"Entered into 2 with b= "<<b<<" and c= "<<c<<endl;
	if ( lazy[i].a2!=0)
	{
		tree[i]= (tree[i]+ ( (ll) (c - b + 1)*(lazy[i].a2))%mod)%mod ;
		if ( b != c)
		{
			lazy[ 2*i].y = 1 ;
			lazy[ 2*i].a2= (lazy[2*i].a2+lazy[i].a2)%mod;
			lazy[ 2*i + 1].y = 1  ;
			lazy[ 2*i+1].a2= (lazy[2*i+1].a2+lazy[i].a2)%mod;
			lazy[ 2*i + 1].a2t = lazy[i].a2t;
			lazy[ 2*i].a2t = lazy[i].a2t ;
		}
	}
	if ( lazy[i].a1!=1)
	{
		tree[i]=(tree[i]*lazy[i].a1)%mod ;
		if ( b != c)
		{
			lazy[ 2*i + 1].y = 1;
			lazy[ 2*i].y = 1 ;
			lazy[ 2*i + 1].a1t = lazy[i].a1t;
			lazy[ 2*i].a1t = lazy[i].a1t ;
			lazy[ 2*i].a1= (lazy[2*i].a1*lazy[i].a1)%mod ;
			lazy[ 2*i+1].a1= (lazy[2*i+1].a1*lazy[i].a1)%mod ;
		}
	}
	
	}
	clear(i);
}
// OPERATION 1 //
void update1( int i , int b , int c , int s , int e ,int  v){
	if(i>=size)return;
	propogate( i , b , c );
	if ( ( e < b) || ( c < s) )
	{
		return ;
	}

	if ( ( s <= b) && ( c <= e) )
	{
		tree[i]=(tree[i]*v)%mod ;
		if ( b != c)
		{  
			propogate(2*i,b,(b+c)/2);	
			propogate(2*i+1,((b+c)/2)+1,c);	
			lazy[ 2*i + 1].y = 1 ;
			lazy[ 2*i].y =  1  ;
			lazy[ 2*i].a1 = (lazy[2*i].a1* (ll)v)%mod ;
			lazy[ 2*i+1].a1 = (lazy[2*i+1].a1* (ll)v)%mod ;
			lazy[2*i].a1t=time1;
			lazy[2*i+1].a1t=time1;
			propogate(2*i,b,(b+c)/2);	
			propogate(2*i+1,((b+c)/2)+1,c);	
		//update1( 2*i , b , (b + c )/ 2 , s , e  , v );
		//update1( 2*i + 1 , ( (b + c )/ 2 + 1 ) , c , s , e , v );
		}
		return ;
	}
	update1( 2*i , b , (b + c )/ 2 , s , e  , v );
	update1( 2*i + 1 , ( (b + c )/ 2 + 1 ) , c , s , e , v );
	tree[i] = (tree[2*i] + tree[2*i + 1])%mod;

}
// OPERATION 2 //
void update2( int i , int b , int c , int s , int e , int v ){
	propogate( i , b , c );
	if(i>=size)return ;
	if ( ( e < b) || ( c < s) )
	{
		return ;
	}

	if ( ( s <= b) && ( c <= e) )
	{
		tree[i]= (tree[i]+ ( (ll) ( c - b + 1) *  (ll)v )%mod)%mod; ;
		if ( b != c)
		{  
			propogate(2*i,b,(b+c)/2);	
			propogate(2*i+1,((b+c)/2)+1,c);	
			lazy[ 2*i + 1].y = 1 ;
			lazy[ 2*i].y =  1  ;
			lazy[ 2*i].a2 = (lazy[2*i].a2%mod+ (ll)v)%mod ;
			lazy[ 2*i+1].a2 = (lazy[2*i+1].a2%mod+ (ll)v)%mod ;
			lazy[2*i].a2t=time1;
			lazy[2*i+1].a2t=time1;
			propogate(2*i,b,(b+c)/2);	
			propogate(2*i+1,((b+c)/2)+1,c);	
		//update1( 2*i , b , (b + c )/ 2 , s , e  , v );
		//update1( 2*i + 1 , ( (b + c )/ 2 + 1 ) , c , s , e , v );	
		}
		return ;
	}
	update2(2*i , b , (b + c )/ 2 , s , e  , v );
	update2( 2*i + 1 , ( (b + c )/ 2 + 1 ) , c , s , e , v );
	tree[i] = (tree[2*i] + tree[2*i + 1])%mod;
}
// OPERATION 3 //
void update3( int i , int b , int c , int s , int e , int v ){

	propogate( i , b , c );
	if ( ( e < b) || ( c < s) )
	{
		return ;
	}

	if ( ( s <= b) && ( c <= e) )
	{
		tree[i] =  (  (ll)( c - b + 1) * (ll) v )%mod ;
		if ( b != c)
		{
			lazy[ 2*i].a3 = 1 ;
			lazy[ 2*i].x= (ll) v;
			lazy[ 2*i].a1= 1ll;
			lazy[ 2*i].d= 0;
			lazy[ 2*i].a2= 0;
			lazy[ 2*i].y =  1  ;
			lazy[ 2*i + 1].y =  1  ;
			lazy[ 2*i + 1].a3 = 1;
			lazy[2*i + 1].x = (ll)v;
			lazy[2*i + 1].a1 = 1ll;
			lazy[2*i + 1].d = 0;
			lazy[2*i + 1].a2 = 0;
		}
		return ;
	}
	update3( 2*i , b , (b + c )/ 2 , s , e  , v );
	update3( 2*i + 1 , ( (b + c )/ 2 + 1 ) , c , s , e , v );
	tree[i] = (tree[2*i] + tree[2*i + 1])%mod;
}
// OPERATION 4 //
ll   query( int i , int b , int c , int s ,int e){
	propogate(i , b , c);
	ll  x , y ;
	if ( ( e < b) || ( s > c) )
	{
		return 0 ;
	}

	if ( (s <=b) && ( c<= e))
	{
		return tree[i]%mod;
	}
	x = query( 2 * i , b , ( b + c )/ 2 , s ,e );
	y = query( 2*i + 1 , ((b+c)/2 + 1 ) , c , s , e );
	return ( x + y )%mod;
}

int main(){   
	ll   r;
	int t , n  , h , q , i , s , e , type,v;
		scanf("%d%d" , &n , &q);
		h = (ceil)( log2(n));
		size = 1<<( h + 1);
		for ( i = 1 ; i < size ; i++)
		{
			tree[i] = 0 ;
			clear(i);
		}
		for ( i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
		}
		create( 1 , 0 , n - 1);
		while(q--)
		{
			time1++;
			scanf("%d" ,&type);
			if ( type == 2)
			{
				scanf("%d%d%d" , &s , &e,&v);
				s--;
				e--;
				v%=mod;
				update1( 1 , 0 , n-1 ,s , e,v);
			}
			else if ( type == 1)
			{
				scanf("%d%d%d" , &s , &e , &v);
				s--;
				e--;
				v%=mod;
				update2( 1 , 0 , n - 1 , s , e , v);
			}
			else if ( type == 3)
			{
				scanf("%d%d%d" , &s , &e , &v);
				s--;
				e--;
				v%=mod;
				update3( 1 , 0 , n - 1 , s , e , v);
			}
			else
			{
				scanf("%d%d" , &s , &e);
				s--;
				e--;
				r = query( 1 , 0 , n-1 ,s , e );
				printf("%lld" , r);
				printf("\n");
			}
		}
	return 0 ;
}
