/*************************************************************************
	> File Name: SPFA.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月14日 星期一 21时55分01秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 505
const int INF = 0x3fffffff;
int n, dis[MAXN], cnt[MAXN], head[MAXN], pnt;
bool vis[MAXN];

struct Edge {
    int v, c, next;
} p[MAXN * MAXN];

void init()
{
    memset(vis, false, sizeof(vis));
    memset(p, 0, sizeof(p));
    fill(dis, dis + MAXN, INF);
    fill(head, head + MAXN, -1);
    pnt = 0;
}

bool relax(int u, int v, int c)
{
    if (dis[v] > dis[u] + c) {
        dis[v] = dis[u] + c;
        return true;
    }
    return false;
}

bool spfa(int S)
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
                if (++ cnt[v] >= n) return false;
                vis[v] = true;
                q.push(v);
            }
        }
        q.pop();
    }
    return true;
}
