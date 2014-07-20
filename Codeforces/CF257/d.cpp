/*************************************************************************
    > File Name: d.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com
    > Created Time: 2014年07月19日 星期六 21时46分44秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LL long long
#define mp make_pair
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
const LL INF = 1e18;
int n, m, k, u, v, x, cnt, head[MAXN], s, y, ans;
LL dis[MAXN], pnt[MAXN], res[MAXN];
bool vis[MAXN];

map <pair<int, int>, LL> edges;

struct Edge {
    int v, next;
    LL c;
} p[MAXN << 3];

struct Node {
    int Pos;

    Node() {}

    Node(int Pos): Pos(Pos) {}

    bool operator < (const Node a) const {
        return dis[Pos] > dis[a.Pos];
    }
};

void init()
{
    edges.clear();
    fill(dis, dis + MAXN, INF);
    fill(head, head + MAXN, -1);
    fill(pnt, pnt + MAXN, INF);
    memset(p, 0, sizeof(p));
    memset(vis, 0, sizeof(vis));
    memset(res, 0, sizeof(res));
    cnt = ans = 0;
}

void addEdge(int u, int v, LL c)
{
    p[cnt].v = v;
    p[cnt].next = head[u];
    p[cnt].c = c;
    head[u] = cnt ++;
}

bool relax(int u, int v, LL c)
{
    if (dis[v] >= dis[u] + c) {
        if (dis[v] == dis[u] + c) {
            res[v] ++; return false;
        } else {
            res[v] = 1;
        }
        dis[v] = dis[u] + c;
        return true;
    }
    return false;
}

void spfa(int S)
{
    vis[S] = 1;
    dis[S] = 0;
    priority_queue <Node> q;
    q.push(Node(S));
    while (!q.empty()) {
        Node u = q.top();
        vis[u.Pos] = false;
        for (int i = head[u.Pos]; i != -1; i = p[i].next) {
            int v = p[i].v;
            if (relax(u.Pos, v, p[i].c) && !vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
        q.pop();
    }
}

void work()
{
    init();
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d %d", &u, &v, &x);
        addEdge(u, v, x);
        addEdge(v, u, x);
    }
    for (int i = 1; i <= k; i ++) {
        scanf("%d %d", &s, &y);
        if (pnt[s] == INF) {
            pnt[s] = y;
        } else {
            ans ++;
            if (pnt[s] > y) {
                pnt[s] = y;
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (pnt[i] != INF) {
            addEdge(1, i, pnt[i]);
        }
    }
    spfa(1);
    for (int i = 1; i <= n; i ++) {
        if (pnt[i] != INF) {
            if (dis[i] == pnt[i]) {
                if (res[i] > 1) ans ++;
            } else {
                ans ++;
            }
        }
    }
    printf("%d\n", ans);
}
int main()
{
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        work();
    }
    return 0;
}
