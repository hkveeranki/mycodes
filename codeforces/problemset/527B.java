/* Author: Hemanth Kumar Veeranki */
/* Handle: harry7 */
import java.io.*;
import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); /*sc for taking input*/
		PrintStream op=System.out;/*op for printing output*/
		int len,i,j,k,ans=0;
		int [][]A= new int[26][26];
		len=sc.nextInt();
		char x,y;
		String a,b;
		a=sc.next();
		b=sc.next();
		for(i=0;i<len;i++){
			x=a.charAt(i);
			y=b.charAt(i);
			if(x!=y) ans++;
			A[x-'a'][y-'a']=i+1;
		}
		for(i=0;i<26;i++)
			for(j=i+1;j<26;j++){
				if(A[i][j]!=0 && A[j][i]!=0){op.print(ans-2+"\n"+A[i][j]+" "+A[j][i]);return ;}
			}
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				for(k=0;k<26;k++)
				if(i!=j && j!=k && A[i][j]!=0 && A[j][k]!=0){
				op.print(ans-1+"\n"+A[i][j]+" "+A[j][k]);
				return ;
				}
		op.print(ans+"\n-1 -1");
	}
}
