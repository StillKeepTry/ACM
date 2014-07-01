/*************************************************************************
	> File Name: Hopcroft_Karp_Graph_Matching(AdjacencyList).cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月01日 星期二 20时05分45秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
const int INF = 0x3fffffff;
int Mx[MAXN], My[MAXN], dx[MAXN], dy[MAXN], x, dis; // 这里的x表示左边集，y表示右边集, M数组表示是否匹配，d数组表示当前深度
bool vis[MAXN];
int head[MAXN], cnt;
struct Edge {
    int v, next;
} p[MAXN * MAXN];

void init()
{
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    cnt = 0;
}

void addEdge(int u, int v)
{
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

bool searchP()
{
    queue<int> Q;
    dis = INF;
    fill(dx, dx + MAXN, -1);
    fill(dy, dy + MAXN, -1);
    for (int i = 1; i <= x; i ++) {
        if (Mx[i] == -1) {
            Q.push(i), dx[i] = 0;
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis) break;
        for (int i = head[u]; i != -1; i = p[i].next) {
            if (dy[p[i].v] == -1) {
                dy[p[i].v] = dx[u] + 1;
                if (My[p[i].v] == -1) dis = dy[p[i].v];
                else {
                    dx[My[p[i].v]] = dy[p[i].v] + 1;
                    Q.push(My[p[i].v]);
                }
            }
        }
    }
    return dis != INF;
}

bool Dfs(int u)
{
    for (int i = head[u]; i != -1; i = p[i].next) {
        vis[p[i].v] = true;
        if (My[p[i].v] != -1 && dy[p[i].v]) continue;
        if (My[p[i].v] == -1 || Dfs(My[p[i].v])) {
            My[p[i].v] = u, Mx[u] = p[i].v;
            return true;
        }
    }
    return false;
}

int MaxMatch()
{
    int res = 0;
    fill(Mx, Mx + MAXN, -1);
    fill(My, My + MAXN, -1);
    while (searchP()) {
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= x; i ++) {
            if (Mx[i] == -1 && Dfs(i)) res ++;
        }
    }
    return res;
}
