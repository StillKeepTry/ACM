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
LL n, m, k, dis[MAXN], cdis[MAXN], u, v, x, cnt, head[MAXN], s, y, ans;
bool vis[MAXN];

map <pair<int, int>, LL> edges;

struct Edge {
    int v, next;
    LL c;
} p[MAXN << 2];

void init()
{
    edges.clear();
    fill(cdis, cdis + MAXN, INF);
    fill(dis, dis + MAXN, INF);
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    memset(vis, 0, sizeof(vis));
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
    if (dis[v] > dis[u] + c) {
        dis[v] = dis[u] + c;
        return true;
    } 
    return false;
}

void spfa(int S)
{
    vis[S] = 1;
    dis[S] = 0;
    queue <int> q;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = p[i].next) {
            int v = p[i].v;
            if (relax(u, v, p[i].c) && !vis[v]) {
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
        cin >> u >> v >> x;
        pair <int, int> edge = mp(u, v);
        if (edges.find(edge) == edges.end()) {
            edges.insert(mp(edge, x));
        } else {
            edges[edge] = Min(edges[edge], x);
        }
    }
    for (map <pair<int, int>, LL>::iterator it = edges.begin(); it != edges.end(); it ++) {
        addEdge((it->first).first, (it->first).second, it->second);
    }
    for (int i = 1; i <= k; i ++) {
        cin >> s >> y;
        if (cdis[s] == INF) {
            cdis[s] = y;
        } else {
            if (cdis[s] > y) {
                ans ++;
                cdis[s] = y;
            } else {
                ans ++;
            }
        }
    }
    spfa(1);
    for (int i = 1; i <= n; i ++) {
        if (cdis[i] >= dis[i] && cdis[i] != INF) {
            ans ++;
        }
    }
    cout << ans << endl;
}
int main()
{
 //   freopen("in", "r", stdin);
    while (cin >> n >> m >> k) {
        work();
    }
    return 0;
}
