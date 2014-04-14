/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月22日 星期六 23时23分32秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a<b) a=b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a>b) a=b;}
#define LL long long 
#define MAXN 1005
int n, a[MAXN][MAXN], q, l, u, ans;
void work()
{
	ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		ans += a[i][i] * a[i][i];
	}
	ans = ans & 1;
	scanf("%d", &q);
	for (int i = 1; i <= q; i ++) {
		scanf("%d", &l);
		if (l <= 2) {
			scanf("%d", &u);
			if (a[u][u] == 0) {
				ans += 1;
			} else {
				ans -= 1;
			}
			a[u][u] ^= 1;
			ans = (ans + 2) % 2;
		} else {
			printf("%d", ans);
		}
	}
	cout << endl;
}
int main()
{
	scanf("%d", &n);
	work();
    return 0;
}
