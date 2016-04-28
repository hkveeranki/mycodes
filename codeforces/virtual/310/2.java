/* Author: Hemanth Kumar Veeranki */
/* Handle: harry7 */
import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); /*sc for taking input*/
		PrintStream op=System.out;/*op for printing output*/
		int n,i;
		n=sc.nextInt();
		int[] a=new int[n];
		for(i=0;i<n;i++)a[i]=sc.nextInt();
		while(a[0]!=0){
		a[0]=(a[0]+1)%n;
		for(i=1;i<n;i++)
			if(i%2==1)a[i]=(a[i]+n-1)%n;
			else a[i]=(a[i]+1)%n;
		}
		for(i=0;i<n;i++)if(a[i]!=i){op.print("No");return ;}
		op.print("Yes");
	}
}
