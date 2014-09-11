/*************************************************************************
    > File Name: e.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年09月04日 星期四 22时31分09秒
 ************************************************************************/

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define eps 1e-8
#define x first
#define y second
#define MAXN 100005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const int INF = 0x3fffffff;
int n, q, a[MAXN], u, v, w, head[MAXN], cnt, op, pr[MAXN * 20], ans[MAXN], depth[MAXN];
bool vis[MAXN];
map <int, int> prim, dp;

struct Edge {
    int v, next;
} p[MAXN << 1];

void Init_Prime(int n) {
    pr[0] = pr[1] = 1;
    int pn = 1;
    for (int i = 2; i <= n; i ++) {
        if (pr[i]) {
            continue;
        }
        for (int j = i; j <= n; j += i) {
            pr[j] = i;
        }
        prim[i] = pn ++;
    }
}

void init() {
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    memset(vis, false, sizeof(vis));
    cnt = 0;
}

void addEdge(int u, int v) {
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

void dfs(int u) {
    vis[u] = true;
    map <int, int> pre;
    if (a[u] == 0 || a[u] == 1) {
        ans[u] = -1;
    } else {
        int tmp = a[u], now = -1, res = 0;
        while (tmp != 1) {
            int d = pr[tmp];
            while (tmp % d == 0) tmp /= d;
            pre[d] = dp[d];
            if (depth[dp[d]] > res) {
                res = depth[dp[d]];
                now = dp[d];
            }
        }
        ans[u] = now;
        for (map<int, int>::iterator it = pre.begin(); it != pre.end(); it ++) {
            dp[it->first] = u;
        }
    }
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (!vis[v]) {
            dfs(v);
        }
    }
    for (map<int, int>::iterator it = pre.begin(); it != pre.end(); it ++) {
        dp[it->first] = pre[it->first];
    }
}

void solve() {
    dp.clear();
    for (map<int, int>::iterator it = prim.begin(); it != prim.end(); it ++) {
        dp.insert(mp(it->first, -1));
    }
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}


void gao(int u, int h) {
    vis[u] = true;
    depth[u] = h;
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (!vis[v]) {
            gao(v, h + 1);
        }
    }
}

void work()
{
    init();
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i ++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    gao(1, 1);
    solve();
    for (int i = 1; i <= q; i ++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &v);
            printf("%d\n", ans[v]);
        } else {
            scanf("%d %d", &v, &w);
            a[v] = w;
            solve();
        }
    }
}
int main()
{
    Init_Prime(2000000);
    while (scanf("%d %d", &n, &q) != EOF) {
        work();
    }
    return 0;
}
