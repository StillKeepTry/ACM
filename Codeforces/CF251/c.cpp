/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月04日 星期三 23时49分10秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 100005
#define pb push_back
typedef vector<int> vi;
bool vis[MAXN];
LL n, k, p, a[MAXN], cnt, d;
vi ans[MAXN];
void work()
{
    cnt = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i ++) ans[i].clear();
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] & 1) cnt ++;
    }
    d = k - p;
    if (cnt < d || (cnt - d) % 2) {
        printf("NO\n");
    } else {
        if ((n - cnt + (cnt - d) / 2) < p) {
            printf("NO\n");
        } else {
            printf("YES\n");
            int f = 1;
            for (int i = 1; i <= n; i ++) {
                if (f > d) break;
                if (a[i] & 1) {
                    ans[f].pb(a[i]);
                    vis[i] = true;
                    f ++;
                }
            }
            for (int i = 1; i <= n; i ++) {
                if (f > k) break;
                if ((a[i] % 2) == 0) {
                    ans[f].pb(a[i]);
                    vis[i] = true;
                    f ++;
                }
            }
            if (f <= k) {
                int flag = 0;
                for (int i = 1; i <= n; i ++) {
                    if (f > k) break;
                    if (!vis[i] && (a[i] & 1)) {
                        if (flag) {
                            ans[f].pb(a[flag]);
                            ans[f].pb(a[i]);
                            vis[i] = vis[flag] = true;
                            f ++;
                            flag = 0;
                        } else {
                            flag = i;
                        }
                    }
                }
            }
            for (int i = 1; i <= n; i ++) {
                if (!vis[i]) {
                    ans[k].pb(a[i]);
                }
            }
            for (int i = 1; i <= k; i ++) {
                cout << ans[i].size();
                for (int j = 0; j < ans[i].size(); j ++) {
                    cout << " " << ans[i][j];
                }
                cout << endl;
            }
        }
    }
}
int main()
{
    while (cin >> n >> k >> p) {
        work();
    }
	return 0;
}
