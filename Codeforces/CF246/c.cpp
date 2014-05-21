/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月16日 星期五 00时09分15秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define pb push_back
#define x first
#define y second
template <typename T> inline T Abs(T a) {return a>0?a:-a;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
typedef pair<int, int> pii;
typedef vector<int> vi;
vector <pii> ans;
vi pr;
int n, a[MAXN], r[MAXN], p[MAXN], check[MAXN];
vi head[MAXN];
void init()
{
    memset(p, 0, sizeof(p));
    memset(check, 0, sizeof(check));
    pr.clear();
    for (int i = 2; i <= 100000; i ++) {
        if (p[i]) continue;
        for (int j = i<<1; j <= 100000; j += i) {
            p[j] = 1;
        }
        pr.pb(i-1);
        head[i-1].pb(i-1);
    }
    for (int i = 0; i < pr.size(); i ++) {
        for (int j = i; j < pr.size(); j ++) {
            int now = pr[i] + pr[j];
            if (now > 100000) break;
            if (!head[now].size()) {
                head[now].pb(pr[i]);
                head[now].pb(pr[j]);
            }
        }
    }
    for (int i = 1; i <= 100000; i ++) {
        if (!head[i].size()) {
            head[i].pb(1);
            head[i].pb(head[i-1][0]);
            head[i].pb(head[i-1][1]);
        }
    }
}
void Swap(int i, int j)
{
    r[a[j]] = i;
    r[a[i]] = j;
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void work()
{
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        r[a[i]] = i;
    }
    ans.clear();
    for (int i = 1; i <= n; i ++) {
        int dis = Abs(i - r[i]);
        int now = r[i];
        int pos = 1;
        if (r[i] > i) pos *= -1;
        for (int j = 0; j < head[dis].size(); j ++) {
            Swap(now, now + pos * head[dis][j]);
            ans.pb(pii(now, now + pos * head[dis][j]));
            now = now + pos * head[dis][j];
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++) {
        cout << Min(ans[i].x, ans[i].y) << " " << Max(ans[i].x, ans[i].y) << endl;
    }
}
int main()
{
    //freopen("in", "r", stdin);
    init();
    while (cin >> n) {
        work();
    }
	return 0;
}
