/*************************************************************************
	> File Name: hungry_Graph_Matching(AdjacencyList).cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月01日 星期二 19时58分45秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 205
int head[MAXN], matchs[MAXN], cnt, n; // n为左边集的点数
bool vis[MAXN];

struct Edge {
    int v, next;
} p[MAXN * MAXN];

void init()
{
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    memset(matchs, 0, sizeof(matchs));
    cnt = 0;
}

void addEdge(int u, int v)
{
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

bool Dfs(int u)
{
    for (int i = head[u]; i != -1; i = p[i].next) {
        if (!vis[p[i].v]) {
            vis[p[i].v] = true;
            if (matchs[p[i].v] == 0 || Dfs(matchs[p[i].v])) {
                matchs[p[i].v] = u;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch()
{
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        memset(vis, false, sizeof(vis));
        if (Dfs(i)) {
            res ++;
        }
    }
    return res;
}
