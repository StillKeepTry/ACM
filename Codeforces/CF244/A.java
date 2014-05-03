/*************************************************************************
    > File Name: A.java
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年05月02日 星期五 23时08分04秒
 ************************************************************************/

import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static int MAXN = 100005;
	public static int n, now, cnt, ans, a[] = new int[MAXN];
	
	public static int Max(int a, int b) {
		return a > b ? a : b;
	}
	
	public static void work(Scanner in, PrintWriter out) {
		n = in.nextInt();
		now = cnt = ans = 0;
		for (int i = 1; i <= n; i ++) {
			a[i] = in.nextInt();
			if (a[i] > 0) {
				if (cnt < 0) {
					ans += -cnt;
					cnt = 0;
				}
			} 
			cnt += a[i];
		}
		if (cnt < 0) ans = ans - cnt;
		out.println(ans);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		while (in.hasNext()) {
			work(in, out);
		}
		in.close();
		out.close();
	}
}

