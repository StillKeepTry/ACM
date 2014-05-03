import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class C {
	public static int MAXN = 205, INF = 0x3f3f3f3f;
	
    public static int n, k, ans, a[] = new int[MAXN];
	
    public static Vector<Integer> v1, v2;
    
    public static int Max(int a, int b) {
    	return a > b ? a : b;
    }
    
	public static void work(Scanner in, PrintWriter out) {
		n = in.nextInt();
		k = in.nextInt();
		ans = -INF;
		for (int i = 1; i <= n; i ++) {
			a[i] = in.nextInt(); 
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = i; j <= n; j ++) {
				v1 = new Vector<Integer>();
				v2 = new Vector<Integer>();
				for (int p = 1; p <= n; p ++) {
					if (p >= i && p <= j) {
						v1.add(a[p]);
					} else {
						v2.add(a[p]);
					}
				}
				Collections.sort(v1);
				Collections.sort(v2);
				Collections.reverse(v2);
				for (int p = 0; p < k && p < v1.size() && p < v2.size(); p ++) {
					v1.set(p, Max(v1.get(p), v2.get(p)));  
				}
				int tmp = 0;
				for (int p = 0; p < v1.size(); p ++) {
					tmp = tmp + v1.get(p);
				}
				ans = Max(ans, tmp);
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