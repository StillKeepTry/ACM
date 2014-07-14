/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月13日 星期日 20时57分16秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 100005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
const int INF = 0x3fffffff;
int n, a[MAXN], flag, ans, x[MAXN];
int l[MAXN], r[MAXN], len[MAXN];
void work()
{
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    flag = 1;
    memset(x, 0, sizeof(x));
    memset(len, 0, sizeof(len));
    fill (l, l + MAXN, INF);
    fill (r, r + MAXN, 0);
    for (int i = 1; i <= n; i ++) {
        if (a[i] > a[i-1]) {
            x[i] = flag;
        } else {
            flag ++;
            x[i] = flag;
        }
        l[flag] = Min(l[flag], i);
        r[flag] = Max(r[flag], i);
    }
    for (int i = 1; i <= flag; i ++) {
        len[i] = r[i] - l[i] + 1;
    }
    ans = 0;
    for (int i = 1; i <= flag; i ++) {
        if (i == 1) {
            ans = Max(ans, len[i]);
        } else {
            ans = Max(ans, len[i]);
            ans = Max(ans, len[i] + 1);
            ans = Max(ans, len[i-1] + 1);
            if (len[i] == 1) {
                ans = Max(ans, len[i-1] + 1);
            } else if (len[i-1] == 1) {
                ans = Max(ans, len[i-1] + len[i]);
            } else {
                int x1 = r[i-1], x2 = l[i];
                if (a[x1] + 1 < a[x2 + 1]) {
                    ans = Max(ans, len[i-1] + len[i]);
                }
                if (a[x1-1] + 1 < a[x2]) {
                    ans = Max(ans, len[i-1] + len[i]);
                }
            }
        }
    }
    printf("%d\n", ans);
}
int main()
{
    while (scanf("%d", &n) != EOF) {
        work();
    }
    return 0; 
}
