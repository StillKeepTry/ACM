/*************************************************************************
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年05月11日 星期日 23时52分37秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, m, a[MAXN], u, v, ans[MAXN], rank[MAXN];
int cmp(int x, int y)
{
	return a[x] < a[y];
}
void work()
{
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		rank[i] = i;
	}
	sort(rank+1, rank+1+n, cmp);
	for (int i = 1; i <= m; i ++) {
		cin >> u >> v;
	}
	int now = 0;
	for (int i = 1; i <= n; i ++) {
		ans[rank[i]] = now;
		now ^= 1;
	}
	for (int i = 1; i <= n; i ++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
int main()
{
	while (cin >> n >> m) {
		work();
	}
	return 0; 
}
