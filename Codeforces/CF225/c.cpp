/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014/1/21 0:36:37
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define pb push_back
int n, m, u, v, e, d, x, val;
int a[MAXN];
vector <int> graph[MAXN];
void clear()
{
	memset(graph, 0, sizeof(graph));
	e = 0;
}
void work()
{
	clear();
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n-1; i ++) {
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	for (int i = 1; i <= m; i ++) {
		cin >> d >> x;
		if (d == 1) {
			cin >> val;
		} else {

		}
	}
}
int main()
{
	while (cin >> n >> m) {
		work();
	}
    return 0;
}
