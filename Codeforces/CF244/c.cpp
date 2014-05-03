/*************************************************************************
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年05月03日 星期六 01时38分34秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MOD 1000000007  
#define LL long long
const LL inf = 0x3f3f3f3f;
LL n, m, head[MAXN], cnt, a[MAXN], u, v, dfn[MAXN], low[MAXN], top, st[MAXN], dfnnum, num, f[MAXN];
LL ans[MAXN][2];
bool vis[MAXN], instack[MAXN];
struct Edge {
	int v, next;
} p[MAXN * 3];
void init()
{
	cnt = top = 0;
	dfnnum = 1;
	num = 1;
	memset(p, 0, sizeof(p));
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
	memset(dfn, 0, sizeof(dfn));
	memset(instack, false, sizeof(instack));
	memset(f, 0, sizeof(f));
	memset(ans, inf, sizeof(ans));
}
void addEdge(int u, int v)
{
	p[cnt].v = v;
	p[cnt].next = head[u];
	head[u] = cnt ++;
}
void dfs(int u)
{
	vis[u] = true;
	dfn[u] = low[u] = dfnnum ++;
	instack[u] = true;
	st[++top] = u;
	for (int i = head[u]; i != -1; i = p[i].next) {
		if (!vis[p[i].v]) {
			dfs(p[i].v);
			if (low[p[i].v] < low[u]) {
				low[u] = low[p[i].v];
			}
		} else {
			if (instack[p[i].v] && dfn[p[i].v] < low[u]) {
				low[u] = dfn[p[i].v];
			}
		}
	}
	if (dfn[u] == low[u]) {
		int tmp;
		do {
			tmp = st[top --];
			instack[tmp] = false;
			f[tmp] = num;
		} while (tmp != u);
		num ++;
	}
}
void work()
{
	init();
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> u >> v;
		addEdge(u, v);;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (a[i] < ans[f[i]][0]) {
			ans[f[i]][0] = a[i];
			ans[f[i]][1] = 1;
		} else {
			if (a[i] == ans[f[i]][0]) {
				ans[f[i]][1] ++;
			}
		}
	}
	LL la = 0, la1 = 1;
	for (int i = 1; i < num; i ++) {
		la += ans[i][0];
		la1 *= ans[i][1];
		la1 %= MOD;
	}
	cout << la << " " << la1 << endl;
} 
int main()
{
	freopen("in", "r", stdin);
	while (cin >> n) {
		work();
	}
	return 0;
}
