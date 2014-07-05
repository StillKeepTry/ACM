/*************************************************************************
	> File Name: MaxinumMatchingOnGeneralGraph.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月05日 星期六 21时00分08秒
    > description : g [][] 为权值，这里要建双向边
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 55

deque <int> Q;
int N, M, u, v, n, g[MAXN][MAXN], inq[MAXN], in[MAXN], inpath[MAXN], match[MAXN], pre[MAXN], base[MAXN];
vector <int> ans;
vector < pair<int, int> > edge;

int Find(int u, int v)
{
    memset(inpath, 0, sizeof(inpath));
    while (1) {
        u = base[u];
        inpath[u] = 1;
        if (match[u] == -1) break;
        u = pre[match[u]];
    }
    while (1) {
        v = base[v];
        if (inpath[v]) return v;
        v = pre[match[v]];
    }
}

void Reset(int u, int fa)
{
    while (u != fa) {
        int v = match[u];
        in[base[u]] = 1;
        in[base[v]] = 1;
        v = pre[v];
        if (base[v] != fa) pre[v] = match[u];
        u = v;
    }
}

void contract(int u, int v, int n)
{
    int fa = Find(u, v);
    memset(in, 0, sizeof(in));
    Reset(u, fa); Reset(v, fa);
    if (base[u] != fa) pre[u] = v;
    if (base[v] != fa) pre[v] = u;
    for (int i = 1; i <= n; i ++) {
        if (in[base[i]]) {
            base[i] = fa;
            if (!inq[i]) {
                Q.push_back(i);
                inq[i] = 1;
            }
        }
    }
}

bool bfs(int s)
{
    fill(pre, pre + MAXN, -1);
    memset(inq, 0, sizeof(inq));
    for (int i = 0; i <= n; i ++) base[i] = i;
    Q.clear();
    Q.push_back(s);
    inq[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for (int v = 1; v <= n; v ++) {
            if (g[u][v] && base[v] != base[u] && match[u] != v) {
                if (v == s || (match[v] != -1 && pre[match[v]] != -1)) {
                    contract(u, v, n);
                } else if (pre[v] == -1) {
                    pre[v] = u;
                    if (match[v] != -1) {
                        Q.push_back(match[v]), inq[match[v]] = 1;
                    } else {
                        u = v;
                        while (u != -1) {
                            v = pre[u];
                            int w = match[v];
                            match[u] = v;
                            match[v] = u;
                            u = w;
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int graph_match()
{
    fill(match, match + MAXN, -1);
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        if (match[i] == -1 && bfs(i)) res ++;
    }
    return res;
}

void init()
{
    memset(g, 0, sizeof(g));
    edge.clear();
    ans.clear();
}


void work()
{

}
int main()
{
    return 0;
}
