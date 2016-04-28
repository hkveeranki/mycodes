/* Author: Hemanth Kumar Veeranki */
/* Handle: harry7 */
import java.io.*;
import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); /*sc for taking input*/
		PrintStream op=System.out;/*op for printing output*/
		for(int t=sc.nextInt();t!=0;t--){
			int i,n;
			long ans=0;
			n=sc.nextInt();
			long[] a=new long[n+1];
			for(i=0;i<n;i++){
				a[i]=sc.nextLong();
				if(i!=0)ans+=Math.max(a[i-1],a[i]);
			}
			op.println(ans);
		}
	}
}
