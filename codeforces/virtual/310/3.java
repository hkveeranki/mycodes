/* Author: Hemanth Kumar Veeranki */
/* Handle: harry7 */
import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); /*sc for taking input*/
		PrintStream op=System.out;/*op for printing output*/
		int n,k,i,j,a=0,b=0,x,y;
		n=sc.nextInt();
		k=sc.nextInt();
		for(i=0;i<k;i++){
			x=sc.nextInt();
			y=sc.nextInt();
			a+=(x-1);
			if(y==1){
				for(j=1;j<x;j++){
					y=sc.nextInt();
					if(y==j+1){
						b=j;
						a--;
					}
				}
			}
			else for(j=1;j<x;j++)y=sc.nextInt();
		}
		op.print(a+n-b-1);
	}
}
