/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月06日 星期日 21时00分52秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
const int INF = 0x3fffffff;
int n, m, x[MAXN], a[MAXN * MAXN], b[MAXN * MAXN], c[MAXN * MAXN];
double ans;

LL V, E;

int head[MAXN], cnt;
struct Edge {
    int v, c, next;
} p[MAXN * MAXN * 2];

void init()
{
    memset(p, 0, sizeof(p));
    fill(head, head + MAXN, -1);
    cnt = 0;
}

void work()
{
    init();
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        addEdge(a[i], b[i], c[i]);
        addEdge(b[i], a[i], c[i]);
    }
    if (m == 0) {
        printf("%.9lf\n", 0.0); return ;
    }
    ans = 0;
    for (int i = 1; i <= m; i ++) {
        LL V = x[a[i]] + x[b[i]];
        LL E = c[i];
        ans = Max(ans, (double)V / (double)E);
    }
    printf("%.9lf\n", ans);
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF) {
        work();
    }
    return 0;
}
