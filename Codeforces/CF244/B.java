/*************************************************************************
    > File Name: B.java
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年05月02日 星期五 23时08分48秒
 ************************************************************************/

import java.io.PrintWriter;
import java.util.Deque;
import java.util.Scanner;

public class B {
	public static int MAXN = 200005;
	
	public static int n, t, c, a[] = new int[MAXN], top, rail;
	
	public static int ans, q[] = new int[MAXN];
	
	public static void work(Scanner in, PrintWriter out) {
		n = in.nextInt();
		t = in.nextInt();
		c = in.nextInt();
		for (int i = 1; i <= n; i ++) {
			a[i] = in.nextInt(); 
		}
		top = rail = 1;
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] > t) {
				top = rail;
			} else {
				q[rail ++] = a[i];
				if (rail - top > c) {
					top ++;
				}
				if (rail - top == c) {
					ans ++;
				}
			}
		}
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