/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月04日 星期四 17时23分31秒
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
#define MAXN 1005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, K, a[10][MAXN], pos[10][MAXN], head[MAXN], cnt, dp[MAXN];

struct Edge {
    int v, next;
} p[MAXN * MAXN];

void init() {
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    fill(dp, dp + MAXN, -1);
    cnt = 0;
}

void addEdge(int u, int v) {
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

void dfs(int u) {
    dp[u] = 1;
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (dp[v] < 0) {
            dfs(v);
        }
        dp[u] = Max(dp[u], dp[v] + 1);
    }
}

void work()
{
    init();
    for (int i = 1; i <= K; i ++) {
        for (int j = 1; j <= N; j ++) {
            scanf("%d", &a[i][j]);
            pos[i][a[i][j]] = j; 
        }
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (i != j) {
                int op = 0;
                for (int k = 1; k <= K; k ++) {
                    if (pos[k][i] >= pos[k][j]) {
                        op = 1; break;
                    }
                }
                if (!op) {
                    addEdge(i, j);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i ++) {
        if (dp[i] < 0) {
            dfs(i);
        }
        ans = Max(ans, dp[i]);
    }
    printf("%d\n", ans);
}
int main()
{
    while (scanf("%d %d", &N, &K) != EOF) {
        work();
    }
    return 0;
}
