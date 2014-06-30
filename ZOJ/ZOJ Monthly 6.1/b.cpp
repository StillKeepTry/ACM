/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月30日 星期一 20时49分00秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n, m, u, v, cnt, f[MAXN << 2], d[MAXN << 2], c[MAXN << 2], nn[MAXN];
char op[2];
int father(int x)
{
    if (f[x] == x) return x;
    int fx = f[x];
    f[x] = father(f[x]);
    d[x] = (d[x] + d[fx]) % 2;
    return f[x];
}
void init()
{
    cnt = n;
    for (int i = 1; i <= n; i ++) {
        f[i] = i, d[i] = 0, c[i] = 1, nn[i] = i;
    }
}
void Union(int x, int y)
{
    int fx = father(x), fy = father(y);
    if (fx != fy) {
        c[fy] += c[fx];
        d[fx] = (d[y] + 1 - d[x] + 2) % 2;
        f[fx] = fy;
    }
}
void Dis(int x)
{
    int fx = father(nn[x]);
    c[fx] --;
    nn[x] = ++ cnt;
    f[cnt] = cnt, d[cnt] = 0, c[cnt] = 1;
}
void work()
{
    init();
    for (int i = 1; i <= m; i ++) {
        scanf("%s", op);
        if (op[0] == 'L') {
            scanf("%d %d", &u, &v);
            Union(nn[u], nn[v]);
        } else if (op[0] == 'D') {
            scanf("%d", &u);
            Dis(u);
        } else if (op[0] == 'Q') {
            scanf("%d %d", &u, &v);
            u = nn[u], v = nn[v];
            int fu = father(u), fv = father(v);
            if (fu != fv) {
                printf("Unknown\n");
            } else {
                if (d[u] == d[v]) {
                    printf("Same\n");
                } else {
                    printf("Different\n");
                }
            }
        } else if (op[0] == 'S') {
            scanf("%d", &u);
            u = nn[u];
            int fu = father(u);
            printf("%d\n", c[fu]);
        }
    }
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF) {
        work();
    }
    return 0;
}
