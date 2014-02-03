/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014/1/13 0:28:11
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
string str;
int a[MAXN] = {};
int b[MAXN] = {};
int m, l, r, len;
int getAns()
{
	int last = a[l-1];
	int len = r - l + 1;
	int d = a[r] - a[l] + 1;
}
void work()
{
	len = str.size();
	for (int i = 0; i < len; i ++) {
		if (str[i] == ')') {
			a[i] = a[i-1] + 1;
			b[i] = b[i-1];
		} else {
			a[i] = a[i-1];
			b[i] = b[i-1] + 1;
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> l >> r;
		int d = b[l] - b[l-1];
		
	}
}
int main()
{
	while (cin >> str) {
		work();
	}
    return 0;
}
