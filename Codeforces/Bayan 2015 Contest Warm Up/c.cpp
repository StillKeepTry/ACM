/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月07日 星期二 20时21分51秒
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
#define MAXN 2005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const int INF = 0x3fffffff;
int N, M, Mat[MAXN][MAXN], ans, dp[MAXN][MAXN], cnt, sx, sy;
char s[MAXN];

int calc(int lx, int ly, int rx, int ry) {
    return dp[rx][ry] + dp[lx - 1][ly - 1] - dp[lx - 1][ry] - dp[rx][ly - 1];
}

bool gao(int sx, int sy, int W, int H) {
    int ans = W * H, area = W * H;;
    while (1) {
        if (Mat[sx][sy + H] && Mat[sx + W][sy]) {
            return false;
        }
        if (calc(sx, sy, sx + W - 1, sy + H - 1) != area) {
            return false;
        }
        int flag = 0;
        if (sx + W - 1 <= N) {
            while (sy + H - 1 <= M) {
                if (sy + H <= M && Mat[sx][sy + H]) {
                    if (calc(sx, sy + 1, sx + W - 1, sy + H) == area) {
                        flag = 1;
                        sy ++;
                        ans += W;
                        if (Mat[sx][sy + H] && Mat[sx + W][sy]) {
                            return false;
                        }
                    } else {
                        return false;
                    }
                } else {
                    break;
                }
            }
        }
        if (sy + H - 1 <= M) {
            while (sx + W - 1 <= N) {
                if (sx + W <= N && Mat[sx + W][sy]) {
                    if (calc(sx + 1, sy, sx + W, sy + H - 1) == area) {
                        flag = 1;
                        sx ++; 
                        ans += H;
                        if (Mat[sx][sy + H] && Mat[sx + W][sy]) {
                            return false;
                        }
                    } else {
                        return false;
                    }
                } else {
                    break;
                }
            }
        }
        if (!flag) {
            break;
        }
    }
    return ans == cnt;
}

void work()
{
    cnt = 0;
    memset(Mat, 0, sizeof(Mat));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i ++) {
        scanf("%s", s);
        for (int j = 1; j <= M; j ++) {
            Mat[i][j] = s[j - 1] == 'X' ? 1 : 0;
            cnt += Mat[i][j];
        }
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + Mat[i][j];
        }
    }
    int flag = 0;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            if (Mat[i][j]) {
                sx = i, sy = j;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    ans = INF;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            if (i * j < ans && gao(sx, sy, i, j)) {
                ans = i * j;
            }
        }
    }
    if (ans == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
}
int main()
{
    while (scanf("%d %d", &N, &M) != EOF) {
        work();
    }
    return 0;
}
