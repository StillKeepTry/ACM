/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月30日 星期四 23时29分10秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
string s, t;
int a, b, c, d;
int ans;
void work()
{
	ans = 0;
	cin >> t;
	a = (t[0] - '0') * 10 + t[1] - '0';
	b = (t[3] - '0') * 10 + t[4] - '0';
	c = (s[0] - '0') * 10 + s[1] - '0';
	d = (s[3] - '0') * 10 + s[4] - '0';
	for (int i = 0; i < a; i ++) {
		c = (c - 1 + 24) % 24;
	}
	if (b <= d) {
		d -= b;
	} else {
		c = (c - 1 + 24) % 24;
		d = d + 60 - b;
	}
	printf("%02d:%02d\n", c, d);
}
int main()
{
	while (cin >> s) {
		work();
	}
    return 0;
}
