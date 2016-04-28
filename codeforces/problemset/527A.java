/* Author: Hemanth Kumar Veeranki */
/* Handle: harry7 */
import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	public static long solve(long a,long b){
		long ans=0;
		while(a!=0 && b!=0){
			if(a>b){
				ans+=(a/b);
				a%=b;
			}
			else{
				ans+=(b/a);
				b%=a;
			}	
		}
		return ans;
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); /*sc for taking input*/
		PrintStream op=System.out;/*op for printing output*/
		long a,b;
		a=sc.nextLong();
		b=sc.nextLong();
		op.print(solve(a,b));
	}
}
