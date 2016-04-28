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
			int b=sc.nextInt();
		while(b-- >0){
			BigInteger p=BigInteger.valueOf(sc.nextInt());
			BigInteger m=BigInteger.valueOf(sc.nextInt());
			BigInteger n=BigInteger.valueOf(sc.nextInt());
			System.out.println((p.modPow(m,n)));
		}
			b=sc.nextInt();
	}
}
