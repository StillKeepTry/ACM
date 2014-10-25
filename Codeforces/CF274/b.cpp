/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月25日 星期六 01时14分58秒
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
#define lson pos << 1
#define rson (pos << 1) | 1
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, M, L, R, Q;

bool flag;

struct SegmentTree {
    struct {
        int value, flag;
    } Segment[MAXN << 2];

    void build(int l, int r, int pos) {
        int mid = (l + r) >> 1;
        Segment[pos].value = Segment[pos].flag = 0;
        if (l == r) return ;
        build(l, mid, lson);
        build(mid + 1, r, rson);
    }

    void pushdown(int pos) {
        if (Segment[pos].value) {
            Segment[lson].value |= Segment[pos].value;
            Segment[rson].value |= Segment[pos].value;
            Segment[lson].flag |= Segment[pos].value;
            Segment[rson].flag |= Segment[pos].value;
            Segment[pos].value = Segment[pos].flag = 0;
        }
    }

    void pushup(int pos) {
        Segment[pos].flag = Segment[lson].flag & Segment[rson].flag;
    }

    void update(int l, int r, int pos, int L, int R, int value) {
        if (l <= L && R <= r) {
            Segment[pos].value |= value;
            Segment[pos].flag |= value;
            return ;
        }
        int mid = (L + R) >> 1;
        pushdown(pos);
        if (mid >= l) update(l, r, lson, L, mid, value);
        if (mid < r) update(l, r, rson, mid + 1, R, value);
        pushup(pos);
    }

    int query(int l, int r, int pos, int L, int R) {
        if (l <= L && R <= r) {
            return Segment[pos].flag;
        }
        pushdown(pos);
        int mid = (L + R) >> 1;
        int ans = (1 << 30) - 1;
        if (mid >= l) ans &= query(l, r, lson, L, mid);
        if (mid < r) ans &= query(l, r, rson, mid + 1, R);
        pushup(pos);
        return ans;
    }
} st;

pair < PII , int > node[MAXN];

void work()
{
    for (int i = 1; i <= M; i ++) {
        cin >> L >> R >> Q;
        node[i].x.x = L, node[i].x.y = R;
        node[i].y = Q;
        st.update(L, R, 1, 1, N, Q);
    }
    for (int i = 1; i <= M; i ++) {
        L = node[i].x.x, R = node[i].x.y, Q = node[i].y;
        int flag = st.query(L, R, 1, 1, N);
        if (flag != Q) {
            printf("NO\n"); return ;
        }
    }
    printf("YES\n");
    int ans;
    for (int i = 1; i <= N; i ++) {
        ans = st.query(i, i, 1, 1, N);
        printf("%d%c", ans, " \n"[i == N]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> N >> M) {
        work();
    }
    return 0;
}
