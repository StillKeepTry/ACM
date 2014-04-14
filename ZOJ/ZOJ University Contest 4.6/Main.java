/*************************************************************************
    > File Name: d.java
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月06日 星期日 22时05分15秒
 ************************************************************************/
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.math.*;
import java.util.*;

public class Main {
	public static int t, a, s, n, num, ans[] = new int[2005], pos;
	
	public static String d;
	
	public static List<Node> list;
	
	public static void work(Scanner in, PrintWriter out) {
		list = new ArrayList<Node>();
		n = in.nextInt();
		num = 0; 
		pos = 0;
		for (int i = 1; i <= n; i ++) {
			a = in.nextInt();
			d = in.next();
			s = in.nextInt();
			list.add(new Node(a, d, s, i));
			if (s > 0) {
				num ++;
			}
		}
		Collections.sort(list);
		for (int i = 0; i < (num * 3 / 100); i ++) {
			Node node = list.get(pos);
			ans[node.pos] = 6;
			pos ++;
		}
		for (int i = 0; i < (num * 7 / 100); i ++) {
			Node node = list.get(pos);
			ans[node.pos] = 5;
			pos ++;
		}
		for (int i = 0; i < (num * 20 / 100); i ++) {
			Node node = list.get(pos);
			ans[node.pos] = 4;
			pos ++;
		}
		for (int i = 0; i < (num * 30 / 100); i ++) {
			Node node = list.get(pos);
			ans[node.pos] = 3;
			pos ++;
		}
		for (;pos < list.size();) {
			Node node = list.get(pos);
			if (node.score > 0) {
				ans[node.pos] = 2;
				pos ++;
			} else {
				break;
			}
		}
		for (; pos < list.size();) {
			Node node = list.get(pos);
			ans[node.pos] = 1;
			pos ++;
		}
		for (int i = 1; i <= n; i ++) {
			out.println("LV" + ans[i]);
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		t = in.nextInt();
		for (int i = 1; i <= t; i ++) {
			work(in, out);
		}
		in.close();
		out.close();
	}
}
class Node implements Comparable<Node>{
	int id;
	Date date;
	int score;
	int pos;
	
	Node (int id, String d, int score, int pos) {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd");
		this.id = id;
		this.pos = pos;
		try {
			this.date = sdf.parse(d);
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		this.score = score;
	}

	@Override
	public int compareTo(Node o) {
		// TODO Auto-generated method stub
		if (this.score == o.score) {
			if (this.date.getTime() == o.date.getTime()) {
				if (this.id > o.id) {
					return 1;
				} else {
					return -1;
				}
			} else if (this.date.getTime() > o.date.getTime()){
				return 1;
			} else {
				return -1;
			}
		} else if (this.score > o.score) {
			return -1;
		} else {
			return 1;
		}
	}
}
