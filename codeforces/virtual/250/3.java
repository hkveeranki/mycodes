import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n,m,i,ans=0;
		n=sc.nextInt();
		m=sc.nextInt();
		int[] a=new int[n+2];
		for(i=1;i<=n;i++) a[i]=sc.nextInt();
		for(i=0;i<m;i++)ans+=Math.min(a[sc.nextInt()],a[sc.nextInt()]);
		System.out.print(ans);
	}
}
