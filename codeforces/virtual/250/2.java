/* Author: Hemanth Kumar Veeranki */
/* Handle: harry7 */
import java.io.*;
import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); /*sc for taking input*/
		PrintStream op=System.out;/*op for printing output*/
		int a,b,l;
		a=sc.nextInt();
		b=sc.nextInt();
		Vector<Integer> ans=new Vector<>();
		while(b>0){
			l=b&(-b);
			if(a>=l){
				a-=l;
				ans.add(b);
			}
			b--;
		}
		if(a!=0)op.println("-1");
		else{
			op.println(ans.size());
			Iterator i = ans.iterator();
			while (i.hasNext()) op.print(i.next()+" ");
		}
	}
}
