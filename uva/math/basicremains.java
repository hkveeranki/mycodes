/*
Author: Hemanth Kumar Veeranki
Handle: harry7
*/
import java.io.*;
import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(true){
			int b=sc.nextInt();
			if(b==0)break;
			String p_str = sc.next();
			String m_str = sc.next();
			BigInteger p=new BigInteger(p_str,b);
			BigInteger m=new BigInteger(m_str,b);
			System.out.println((p.mod(m)).toString(b));
		}
	}
}
