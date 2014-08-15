/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月16日 星期六 01时37分18秒
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
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
#define MAXN 1005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
LL n, d, k, ans[MAXN][MAXN];
bool vis[MAXN];

void work()
{
    memset(ans, 0, sizeof(ans));
    if (k >= n) {
        for (int i = 1; i <= d; i ++) {
            for (int j = 1; j <= n; j ++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    } else {
        LL tmp = 1;
        for (int i = 1; i <= d; i ++) {
            tmp = tmp * k;
            if (tmp > n) break;
        }
        if (tmp < n) {
            printf("-1\n"); return ;
        }
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; i ++) {
            if (i == 1) {
                for (int j = 1; j <= d; j ++) {
                    ans[j][i] = 1;
                }
            } else {
                int add = 1;
                for (int j = 1; j <= d; j ++) {
                    ans[j][i] = ans[j][i-1];
                }
                for (int j = 1; j <= d; j ++) {
                    if (ans[j][i] < k) {
                        ans[j][i] ++; break;
                    } else {
                        ans[j][i] = 1;
                    }
                }
            }
        }
        for (int i = 1; i <= d; i ++) {
            for (int j = 1; j <= n; j ++) {
                cout << ans[i][j] << " ";
            }
            printf("\n");
        }
    }
}
int main()
{
    while (cin >> n >> k >> d) {
        work();
    }
    return 0;
}
