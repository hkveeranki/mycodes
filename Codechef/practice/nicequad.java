/* Author: Hemanth Kumar Veeranki */
/* Handle: harry7 */
import java.io.*;
import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); /*sc for taking input*/
		PrintStream op=System.out;/*op for printing output*/
		int t=sc.nextInt();
		for(;t!=0;t--){
			int n,x,y;
			long c1,c2,c3,c4;
			c1=c2=c3=c4=0;
			for(n=sc.nextInt();n!=0;n--){
				x=sc.nextInt();
				y=sc.nextInt();
				if(x<0)
					if(y<0)c3++;
					else c4++;
				else
					if(y<0)c2++;
					else c1++;
			}
			op.println(c1*c2*c3*c4);
		}
	}
}
