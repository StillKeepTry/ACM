/*************************************************************************
	> File Name: Tarjan(SCC).cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月24日 星期四 17时19分42秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
#define MAXN 10005

int head[MAXN], cnt;
int dfn[MAXN], st[MAXN], low[MAXN], dfnnum, num, be[MAXN], top;
bool vis[MAXN], instack[MAXN];

struct Edge {
    int v, next;
} p[MAXN << 2];

void init()
{
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(st, 0, sizeof(st));
    memset(low, 0, sizeof(low));
    memset(be, 0, sizeof(be));
    num = 1, dfnnum = top = 0;
}

void addEdge(int u, int v) 
{
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

void Tarjan(int u)
{
    vis[u] = true;
    dfn[u] = low[u] = dfnnum ++;
    instack[u] = true;
    st[++ top] = u;
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (!vis[v]) {
            Tarjan(v);
            if (low[v] < low[u]) {
                low[u] = low[v];
            }
        } else {
            if (instack[v] && dfn[v] < low[u]) {
                low[u] = dfn[v];
            }
        }
    }
    if (dfn[u] == low[u]) {
        int v;
        do {
            v = st[top --];
            instack[v] = false;
            be[v] = num;
        } while (v != u);
        num ++;
    }
}
