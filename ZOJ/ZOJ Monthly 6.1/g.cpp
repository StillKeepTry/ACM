/*************************************************************************
	> File Name: g.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月01日 星期日 11时58分03秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n, m, cnt, cnt1, s, t, ans, flag, c, top, num, dfnnum;
int head[MAXN], head1[MAXN], deg[MAXN], dfn[MAXN], low[MAXN], st[MAXN], f[MAXN], pnt[MAXN];
bool vis[MAXN], instack[MAXN];
struct Edge {
    int v, next;
} p[MAXN * 3], p1[MAXN];
void init()
{
    memset(pnt, 0, sizeof(pnt));
    memset(p, 0, sizeof(p));
    memset(p1, 0, sizeof(p1));
    memset(deg, 0, sizeof(deg));
    fill (head, head+MAXN, -1);
    fill (head1, head1+MAXN, -1);
    memset(vis, false, sizeof(vis));
    memset(f, 0, sizeof(f));
    memset(instack, false, sizeof(instack));
    memset(st, 0, sizeof(st));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    top = 0;
    cnt = dfnnum = num = cnt1 = 1;
}
void dfs(int u)
{
    vis[u] = true;
    dfn[u] = low[u] = dfnnum ++;
    instack[u] = true;
    st[++ top] = u;
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
void addEdge(int u, int v)
{
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}
void addEdge1(int u, int v)
{
    p1[cnt1].v = v;
    p1[cnt1].next = head1[u];
    head1[u] = cnt1 ++;
}
void Topo()
{
    ans = c = 0;
    queue<int> que;
    for (int i = 1; i <= num; i ++) {
        if (deg[i] == 0) {
            que.push(i);
            c ++;
        }
    }
    flag = 0;
    while (!que.empty()) {
        ans ++;
        vector<int> point;
        while (!que.empty()) {
            point.push_back(que.front());
            pnt[que.front()] --;
            que.pop();
        }
        for (int i = 0; i < point.size(); i ++) {
            if (pnt[point[i]]) {
                que.push(point[i]);
            }
        }
        for (int i = 0; i < point.size(); i ++) {
            for (int j = head1[point[i]]; j != -1; j = p1[j].next) {
                deg[p1[j].v] --;
                if (!deg[p1[j].v]) {
                    que.push(p1[j].v);
                }
            }
        }
    }
}
void work()
{
    init();
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &s, &t);
        addEdge(s, t);
    }
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i ++) {
        pnt[f[i]] ++;
    }
    num --;
    for (int i = 1; i <= n; i ++) {
        for (int j = head[i]; j != -1; j = p[j].next) {
            if (f[i] != f[p[j].v]) {
                addEdge1(f[i], f[p[j].v]);
                deg[f[p[j].v]] += pnt[f[i]];
            }   
        }
    }
    Topo();
    cout << ans << endl;
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF) {
        work();
    }
	return 0;
}
