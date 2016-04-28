/*
	Author: Hemanth Kumar Veeranki
	Handle: harry7
*/
import java.io.*;
import java.util.*;
import java.math.*;
class Main{
	public static int f(int x){
		int sum=x;
		for(;x!=0;x/=10)sum+=(x%10);
		return sum;
	}	
	public static void main(String[] args){
	int lim=10000010,i;
	int m[]=new int[lim];
	for(i=1;i<=1000000;i++)m[i]=0;
		for(i=1;i<lim-10;i++){
			int j=f(i);
			if(j<lim) m[j]=1;
		}
		for(i=1;i<=1000000;i++)if(m[i]==0)System.out.println(i);
	}
}
