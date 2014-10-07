/*************************************************************************
	> File Name: e.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月07日 星期二 00时49分26秒
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
#define MAXN 100005
#define LS(x) (x) << 1
#define RS(x) (x) << 1 | 1
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<LL, LL> PII;
typedef vector<int> vi;
LL N, D, h[MAXN], nh[MAXN], dp[MAXN], ans[MAXN], pre[MAXN];
PII a[MAXN]; 

PII tr[MAXN << 2];

void pushdown(int pos) {
    
}

void pushup(int pos) {
    tr[pos] = tr[LS(pos)];
    if (tr[pos].y < tr[RS(pos)].y) {
        tr[pos] = tr[RS(pos)];
    }
}

void build(int pos, int l, int r) {
    tr[pos].x = 0;
    tr[pos].y = 0;
    if (l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    build(LS(pos), l, mid);
    build(RS(pos), mid + 1, r);
}

void update(int pos, int l, int r, int L, int R, PII now) {
    if (l <= L && R <= r) {
        tr[pos] = now;
        return ;
    }
    pushdown(pos);
    int mid = (L + R) >> 1;
    if (mid >= l) update(LS(pos), l, r, L, mid, now);
    if (mid < r) update(RS(pos), l, r, mid + 1, R, now);
    pushup(pos);
}

PII query(int pos, int l, int r, int L, int R) {
    if (l <= L && R <= r) {
        return tr[pos];
    }
    pushdown(pos);
    int mid = (L + R) >> 1;
    PII now = mp(0, 0);
    if (mid >= l) {
        PII tmp = query(LS(pos), l, r, L, mid);
        if (tmp.y > now.y) {
            now = tmp;
        }
    }
    if (mid < r) {
        PII tmp = query(RS(pos), l, r, mid + 1, R);
        if (tmp.y > now.y) {
            now = tmp;
        }
    }
    return now;
}

struct Node {
    int pos, rank;
    LL h, l, r;
    bool operator < (const Node &next) const {
        return pos < next.pos;
    }
} p[MAXN];

void work()
{
    for (int i = 1; i <= N; i ++) {
        cin >> h[i];
        a[i] = mp(h[i], i);
    }
    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N; i ++) {
        nh[i] = a[i].x;
    }
    for (int i = 1; i <= N; i ++) {
        p[i].pos = a[i].y, p[i].h = a[i].x, p[i].rank = i;
        LL l = p[i].h - D, r = p[i].h + D;
        p[i].r = lower_bound(nh + 1, nh + 1 + N, r) - nh;
        p[i].l = upper_bound(nh + 1, nh + 1 + N, l) - nh;
        if (p[i].l) {
            p[i].l --;
        }
    }
    sort(p + 1, p + 1 + N);
    build(1, 1, N);
    for (int i = 1; i <= N; i ++) {
        PII now = mp(0, 0);
        if (p[i].l) {
            PII tmp = query(1, 1, p[i].l, 1, N);
            if (now.y < tmp.y) {
                now = tmp;
            }
        }
        if (p[i].r <= N) {
            PII tmp = query(1, p[i].r, N, 1, N);
            if (now.y < tmp.y) {
                now = tmp;
            }
        }
        ans[i] = now.y + 1;
        pre[i] = now.x;
        update(1, p[i].rank, p[i].rank, 1, N, mp(i, ans[i]));
    }
    int MaxLen = 0, start;
    for (int i = 1; i <= N; i ++) {
        if (MaxLen < ans[i]) {
            start = i;
            MaxLen = ans[i];
        }
    }
    vi last;
    while (start) {
        last.pb(start);
        start = pre[start];
    }
    reverse(last.begin(), last.end());
    cout << MaxLen << endl;
    for (int i = 0; i < last.size(); i ++) {
        if (i) cout << " ";
        cout << last[i];
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> N >> D) {
        work();
    }
    return 0;
}
