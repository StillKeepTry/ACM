/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月21日 星期日 00时04分58秒
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
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, A, B, p[MAXN], ans[MAXN];
bool vis[MAXN];

map <int, int> ma;
map <int, bool> mb;
vi a, b;
set <int> sa, sb;

bool check() {
    for (int i = 1; i <= N; i ++) {
        int ca = A - p[i], cb = B - p[i];
        if (ma.find(ca) == ma.end() && ma.find(cb) == ma.end()) {
            return false;
        }
    }
    return true;
}

void gao(int u, int op, int &flag) {
    if (ma.find(u) == ma.end()) {
        return ;
    }
    if (op == 0) {
        int ca = A - u;
        if (ma.find(ca) != ma.end()) {
            vis[ma[u]] = vis[ma[ca]] = true;
            ans[ma[u]] = ans[ma[ca]] = 0;
            gao(B - ca, op, flag);
        } else {
            flag = 1;
        }
    } else {
        int cb = B - u;
        if (ma.find(cb) != ma.end()) {
            vis[ma[u]] = vis[ma[cb]] = true;
            ans[ma[u]] = ans[ma[cb]] = 1;
            gao(A - cb, op, flag);
        } else {
            flag = 1;
        }
    }
}

void work()
{
    ma.clear(), mb.clear();
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &p[i]);
        ma[p[i]] = i;
        mb[p[i]] = true;
    }
    if (!check()) {
        printf("NO\n"); return ;
    }
    if (A == B) {
        printf("YES\n");
        for (int i = 1; i <= N; i ++) {
            if (i > 1) printf(" ");
            printf("0");
        }
        printf("\n"); return ;
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= N; i ++) {
        int ca = A - p[i], cb = B - p[i];
        if (!vis[i]) {
            int flag = 0;;
            if (ma.find(ca) != ma.end() && ma.find(cb) == ma.end()) {
                gao(p[i], 0, flag);
                if (flag) {
                    printf("NO\n"); return ;
                }
            }
            flag = 0;
            if (ma.find(cb) != ma.end() && ma.find(ca) == ma.end()) {
                gao(p[i], 1, flag);
                if (flag) {
                    printf("NO\n"); return ;
                }
            }
        }
    }
    printf("YES\n"); 
    for (int i = 1; i <= N; i ++) {
        if (i > 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}
int main()
{
    while (scanf("%d %d %d", &N, &A, &B) != EOF) {
        work();
    }
    return 0;
}
