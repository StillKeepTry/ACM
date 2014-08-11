/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月08日 星期五 22时56分08秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
#define MAXN 100005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n, m, u, v, flag, parity[MAXN], f[MAXN];
int head[MAXN], cnt, x[MAXN], c;
bool vis[MAXN], has[MAXN];
vector <int> path;

struct Edge {
    int v, next;
} p[MAXN << 1];

int father(int x) 
{
    if (f[x] == x) return x;
    f[x] = father(f[x]);
    return f[x];
}

void init()
{
    memset(parity, 0, sizeof(parity));
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i ++) {f[i] = i;}
    memset(has, 0, sizeof(has));
    cnt = c = 0;
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
    parity[u] ^= 1;
    path.pb(u);
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (!vis[v]) {
            dfs(v);
            parity[u] ^= 1;
            path.pb(u);
            if (parity[v] != x[v]) {
                parity[v] ^= 1;
                parity[u] ^= 1;
                path.pb(v);
                path.pb(u);
            }
        }
    }
}

void work()
{
    init();
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
        int fu = father(u);
        int fv = father(v);
        f[fu] = fv;
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; i ++) {
        int fx = father(i);
        if (x[i]) {
            flag = fx;
            if (!has[fx]) {
                has[fx] = true;
                c ++;
            }
        }
    }
    if (c == 0) {
        printf("0\n"); return ;
    } else if (c > 1) {
        printf("-1\n"); return ;
    }
    path.clear();
    dfs(flag);
    int start = 0;
    if (parity[path[0]] != x[path[0]]) {
        start = 1;
    } 
    printf("%d\n", path.size() - start);
    for (int i = start; i < path.size(); i ++) {
        printf("%d%c", path[i], (i == path.size() - 1) ? '\n' : ' ');
    }
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF) {
        work();
    }
    return 0;
}
