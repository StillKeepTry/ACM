/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月28日 星期日 23时58分22秒
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
#define MAXN 2005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, a[MAXN][MAXN], f[MAXN];
LL b[MAXN][MAXN];

struct Node {
    int u, v, d;  

    Node() {}

    Node(int _u, int _v, int _d):u(_u), v(_v), d(_d) {}

    bool operator < (const Node &next) const {
        return d < next.d;
    }
};

vector <Node> edge;

int head[MAXN], cnt;
bool vis[MAXN];

struct Edge {
    int v, next;
    LL d;  
} p[MAXN << 1];

void init() {
    for (int i = 1; i <= N; i ++) {
        f[i] = i;
    }
    memset(p, 0, sizeof(p));
    fill(head, head + MAXN, -1);
    cnt = 0;
}

void addEdge(int u, int v, int d) {
    p[cnt].v = v;
    p[cnt].d = d;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

int father(int x) {
    if (f[x] == x) return x;
    int fx = f[x];
    return f[x] = father(fx);
}

void Union(int u, int v) {
    int fu = father(u);
    int fv = father(v);
    f[fu] = fv;
}

void dfs(int u, int now, LL d) {
    b[now][u] = d;
    vis[u] = true;
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (!vis[v]) {
            dfs(v, now, d + p[i].d);
        }
    }
}

void work()
{
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= N; i ++) {
        if (a[i][i]) {
            printf("NO\n"); return ;
        }
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = i + 1; j <= N; j ++) {
            if (a[i][j] != a[j][i]) {
                printf("NO\n"); return ;
            }
            if (a[i][j] == 0) {
                printf("NO\n"); return ;
            }
        }
    }
    edge.clear();
    for (int i = 1; i <= N; i ++) {
        for (int j = i + 1; j <= N; j ++) {
            edge.pb(Node(i, j, a[i][j]));
        }
    }
    init();
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i ++) {
        int u = edge[i].u, v = edge[i].v, d = edge[i].d;
        if (father(u) != father(v)) {
            Union(u, v);
            addEdge(u, v, (LL)d);
            addEdge(v, u, (LL)d);
        }
    }
    for (int i = 1; i <= N; i ++) {
        memset(vis, 0, sizeof(vis));
        dfs(i, i, 0);
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (a[i][j] != b[i][j]) {
                printf("NO\n"); return ;
            }
        }
    }
    printf("YES\n");
}
int main()
{
    while (scanf("%d", &N) != EOF) {
        work();
    }
    return 0;
}
