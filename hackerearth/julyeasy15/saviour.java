/* Author: Hemanth Kumar Veeranki */
/* Handle: harry7 */
import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); /*sc for taking input*/
		PrintStream op=System.out;/*op for printing output*/
		for(int t=sc.nextInt();t!=0;t--){
			int i,n,j,ans=0;
			n=sc.nextInt();
			int[] a=new int[n+1];
			Arrays.sort(a);
			for(i=0;i<n;i++)a[i]=sc.nextInt();
			for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)if(a[i]!=a[j] && (a[i]+a[j])%2==0)ans++;
			op.println(ans);
		}
	}
}
