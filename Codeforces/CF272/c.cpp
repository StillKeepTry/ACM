/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月12日 星期日 22时49分51秒
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
#define MAXN 505
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const int INF = 0x3fffffff;
char s[MAXN << 2], p[MAXN];
int N, M, ans[MAXN << 2], to[MAXN << 2], dp[MAXN << 2][MAXN << 2];

void work()
{
    scanf("%s", p);
    N = strlen(s);
    M = strlen(p);
    for (int i = 0; i < N; i ++) {
        int j = 0, k = 0;
        while (j < M && (i + k) < N) {
            if (p[j] == s[i + k]) {
                j ++, k ++;
            } else {
                k ++;
            }
        }
        if (j == M) {
            to[i] = i + k - 1;
        } else {
            to[i] = -1;
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[N][0] = 0;
    for (int i = N - 1; i >= 0; i --) {
        for (int j = 0; j <= N - i; j ++) {
            dp[i][j] = Max(dp[i][j], dp[i + 1][j]);
            if (j) {
                dp[i][j] = Max(dp[i][j], dp[i + 1][j - 1]);
            }
            if (to[i] >= 0 && to[i] - i + 1 - M <= j) {
                dp[i][j] = Max(dp[i][j], 1 + dp[to[i] + 1][j - (to[i] - i + 1 - M)]);
            }
        }
    }
    for (int i = 0; i <= N; i ++) {
        if (i) printf(" ");
        printf("%d", dp[0][i]);
    }
    printf("\n");
}
int main()
{
    while (scanf("%s", s) != EOF) {
        work();
    }
    return 0;
}
