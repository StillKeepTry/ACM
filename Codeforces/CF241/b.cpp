/*************************************************************************
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月13日 星期日 15时53分33秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 50005
template <typename T> inline T Min(T a, T b) {return a>b?b:a;}
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
int n, m, t[MAXN][10], a[MAXN][10], ans, c[MAXN][10];
void work()
{
	memset(a, 0, sizeof(a));
	memset(c, 0, sizeof(c));
	ans = 0;
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			cin >> t[i][j];
			if (j == 1) a[i][j] = t[i][j];
			else a[i][j] = a[i][j-1];
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == 1) {
				c[i][j] = c[i][j-1] + t[i][j];
			} else {
				c[i][j] = Max(c[i-1][j], c[i][j-1]) + t[i][j];
			}
		}
	}
	for (int i = 1; i <= m; i ++) {
		cout << c[i][n] << " ";
	}
	cout << endl;
}
int main()
{
	while (cin >> m >> n) {
		work();
	}
	return 0;
}
