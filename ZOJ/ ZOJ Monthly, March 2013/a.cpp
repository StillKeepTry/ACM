/*************************************************************************
	> File Name: zoj_3686.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014å¹´05æ16æ¥ ææäº 16æ¶05å35ç§
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define pb push_back
#define x first
#define y second
#define LS(X) X<<1
#define RS(X) (X<<1)|1
#define MID(l,r) (l+r)>>1
typedef vector<int> vi;
typedef pair<int, int> pii;
int n, m, p, cnt, low[MAXN], c[MAXN<<3], add[MAXN<<3];
bool vis[MAXN];
string op;
vi edge[MAXN];
pii side[MAXN];
void dfs(int u)
{
    vis[u] = true;
    low[u] = ++ cnt;
    for (int i = 0; i < edge[u].size(); i ++) {
        if (!vis[edge[u][i]]) {
            dfs(edge[u][i]);
        }
    }
    side[u].x = low[u], side[u].y = cnt;
}
void pushdown(int pos, int L, int R)
{
    if (c[pos]) {
        c[pos] ^= 1, c[LS(pos)] ^= 1, c[RS(pos)] ^= 1;
        int mid = MID(L,R);
        add[LS(pos)] = mid - L + 1 - add[LS(pos)];
        add[RS(pos)] = R - mid - add[RS(pos)];
    }
}
void pushup(int pos)
{
    add[pos] = add[LS(pos)] + add[RS(pos)];
}
void update(int l, int r, int pos, int L, int R)
{
    if (l <= L && R <= r) {
        c[pos] ^= 1;
        add[pos] = R - L + 1 - add[pos];
        return ;
    }
    int mid = MID(L,R);
    pushdown(pos, L, R);
    if (mid >= l) update(l, r, LS(pos), L, mid);
    if (mid < r) update(l, r, RS(pos), mid+1, R);
    pushup(pos);
}
int query(int l, int r, int pos, int L, int R)
{
    if (l <= L && R <= r) {
        return add[pos];
    }
    pushdown(pos, L, R);
    int mid = MID(L,R), ans = 0;
    if (mid >= l) ans += query(l, r, LS(pos), L, mid);
    if (mid < r) ans += query(l, r, RS(pos), mid+1, R);
    pushup(pos);
    return ans;
}
void work()
{
    cnt = 0;
    memset(vis, false, sizeof(vis));
    memset(c, 0, sizeof(c));
    memset(add, 0, sizeof(add));
    for (int i = 1; i <= n; i ++) edge[i].clear();
    for (int i = 2; i <= n; i ++) {
        scanf("%d", &p);
        edge[p].pb(i);
    }
    dfs(1);
    for (int i = 1; i <= m; i ++) {
        cin >> op >> p;
        int l = side[p].x, r = side[p].y;
        if (op[0] == 'o') {
            update(l, r, 1, 1, n);
        } else {
            cout << query(l, r, 1, 1, n) << endl;
        }
    }
    cout << endl;
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF) {
        work();
    }
	return 0;
}
