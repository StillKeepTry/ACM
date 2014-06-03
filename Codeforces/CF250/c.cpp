/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月01日 星期日 21时12分24秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define LL long long
int n, m, v[MAXN], x[MAXN], y[MAXN], head[MAXN], cnt, sum[MAXN], rank[MAXN];
const int inf = 0x3fffffff;
bool vis[MAXN];
LL ans;
struct Edge {
    int v, next;
} p[MAXN * 2];
void init()
{
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    memset(sum, 0, sizeof(sum));
    cnt = 1;
}
void addEdge(int u, int v)
{
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}
int cmp(int x, int y)
{
    return v[y] < v[x];
}
void work()
{
    init();
    for (int i = 1; i <= n; i ++) {
        cin >> v[i];
        rank[i] = i;
    }
    sort(rank+1, rank+1+n, cmp);
    for (int i = 1; i <= m; i ++) {
        cin >> x[i] >> y[i];
        sum[x[i]] += v[y[i]];
        sum[y[i]] += v[x[i]];
        addEdge(x[i], y[i]);
        addEdge(y[i], x[i]);
    }
    ans = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i ++) {
        ans += sum[rank[i]];
        for (int j = head[rank[i]]; j != -1; j = p[j].next) {
            sum[p[j].v] -= v[rank[i]];
        }
    }
    cout << ans << endl;
}
int main()
{
    while (cin >> n >> m) {
        work();
    }
	return 0;
}
