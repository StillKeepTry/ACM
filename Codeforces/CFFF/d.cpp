/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月14日 星期一 10时24分10秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a>b?a:b;}
const LL INF = 1e18;
LL n, m, k, p, a[MAXN][MAXN], r[MAXN], l[MAXN], b[MAXN * MAXN], c[MAXN * MAXN], top, ans;
void work()
{
    priority_queue <LL> row, col;
    memset(r, 0, sizeof(r));
    memset(l, 0, sizeof(l));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            r[i] = r[i] + a[i][j];
        }
        row.push(r[i]);
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            l[i] = l[i] + a[j][i];
        }
        col.push(l[i]);
    }
    b[0] = c[0] = 0;
    for (int i = 1; i <= k; i ++) {
        top = row.top();
        b[i] = b[i-1] + top;
        row.pop();
        row.push(top - m * p);
        top = col.top();
        c[i] = c[i-1] + top;
        col.pop();
        col.push(top - n * p);
    }
    ans = - INF;
    for (int i = 0; i <= k; i ++) {
        ans = Max(b[i] + c[k - i] - i * (k - i) * p, ans);
    }
    cout << ans << endl;
}
int main()
{
    while (cin >> n >> m >> k >> p) {
        work();
    }
    return 0;
}
