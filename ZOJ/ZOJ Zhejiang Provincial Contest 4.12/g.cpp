/*************************************************************************
    > File Name: g.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月12日 星期六 13时07分55秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int t, a, b, c, ans;
char s1[2], s2[2];
int get(char c, int a, int b)
{
	if (c == '*') return a * b;
	if (c == '/') return a / b;
	if (c == '%') return a % b;
	if (c == '-') return a - b;
	if (c == '+') return a + b;
}
void work()
{
	scanf("%d %s %d %s %d", &a, s1, &b, s2, &c);
	ans = 0;
	if (s1[0] == '/' || s1[0] == '*' || s1[0] == '%') {
		ans = get(s1[0], a, b);
		ans = get(s2[0], ans, c);
	} else {
		if (s1[0] == '+') {
			ans = get(s2[0], b, c);
			ans = get(s1[0], a, ans);
		} else {
			if (s2[0] == '/' || s2[0] == '*' || s2[0] == '%') {
				ans = get(s2[0], b, c);
				ans = get(s1[0], a, ans);
			} else {
				ans = get(s1[0], a, b);
				ans = get(s2[0], ans, c);
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &t);
	while (t --) {
		work();
	}
	return 0;
}
