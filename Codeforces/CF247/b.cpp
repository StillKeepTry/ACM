/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月21日 星期三 23时16分58秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 10
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int a[MAXN][MAXN], p[MAXN], ans;
bool vis[MAXN];
void dfs(int len)
{
    if (len > 5) {
        int tmp = 0;
        for (int i = 1; i <= 5; i ++) {
            for (int j = i;; j += 2) {
                if (j >= 5) break;
                tmp += a[p[j+1]][p[j]];
                tmp += a[p[j]][p[j+1]];
            }
        }
        ans = Max(ans, tmp);
    }
    for (int i = 1; i <= 5; i ++) {
        if (!vis[i]) {
            vis[i] = true;
            p[len] = i;
            dfs(len+1);
            vis[i] = false;
        }
    }
}
void work()
{
    ans = 0;
    for (int i = 2; i <= 5; i ++) cin >> a[1][i];
    for (int i = 2; i <= 5; i ++) {
        for (int j = 1; j <= 5; j ++) {
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;
}
int main()
{
    while (cin >> a[1][1]) {
        work();
    }
	return 0;
}
