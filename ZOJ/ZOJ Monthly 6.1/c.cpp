/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月01日 星期日 12时45分31秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define pb push_back
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
typedef vector<int> vi;
int n, k, a[MAXN], ans, cnt;
vi e[MAXN];
map<int, int> ma;
void work()
{
    ma.clear();
    ans = 0, cnt = 1;
    for (int i = 1; i <= n; i ++) e[i].clear();
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (ma[a[i]] == 0) {
            ma[a[i]] = cnt ++;
        }
        e[ma[a[i]]].pb(i);
    }    
    for (int i = 1; i < cnt; i ++) {
        queue <int> que;
        int len = 0;
        for (int j = 0; j < e[i].size(); j ++) {
            len ++;
            que.push(e[i][j]);
            int last = e[i][j], first;
            while (1) {
                first = que.front();
                if (last - first + 1 > len + k) {
                    que.pop();
                    len --;
                } else {
                    break;
                }
            }
            ans = Max(ans, len);
        }
    }
    cout << ans << endl;
}
int main()
{
    while (scanf("%d %d", &n, &k) != EOF) {
        work();
    }
	return 0;
}
