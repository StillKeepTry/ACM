/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月04日 星期四 22时13分02秒
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
#define MAXN 2005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
int n;
LL a[MAXN][MAXN], ans, dir[MAXN][MAXN][2], Mat[MAXN][MAXN];
LL sx[MAXN][MAXN], sy[MAXN][MAXN];
PII ans1, ans2;

void work()
{
    memset(sx, 0, sizeof(sx));
    memset(sy, 0, sizeof(sy));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            scanf("%I64d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            for (int j = 1; j <= n; j ++) {
                Mat[i][j] = j & 1;
            }
        } else {
            for (int j = 1; j <= n; j ++) {
                Mat[i][j] = 1 ^ Mat[i-1][j];
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        LL add = 0;
        for (int j = i; j <= n; j ++) {
            add += a[j - i + 1][j];
        }
        for (int j = i; j <= n; j ++) {
            sx[j - i + 1][j] = add;
        }
    }
    for (int i = 1; i <= n; i ++) {
        LL add = 0;
        for (int j = i; j <= n; j ++) {
            add += a[j][j - i + 1];
        }
        for (int j = i; j <= n; j ++) {
            sx[j][j - i + 1] = add;
        }
    }
    for (int i = 1; i <= n; i ++) {
        LL add = 0;
        int pnt = i;
        for (int j = 1; j <= i; j ++) {
            add += a[j][pnt --];
        }
        pnt = i;
        for (int j = 1; j <= i; j ++) {
            sy[j][pnt --] = add;
        }
    }
    for (int i = 1; i <= n; i ++) {
        LL add = 0;
        int pnt = n;
        for (int j = i; j <= n; j ++) {
            add += a[j][pnt --];
        }
        pnt = n;
        for (int j = i; j <= n; j ++) {
            sy[j][pnt --] = add;
        }
    }
    LL ma = -1, ma1 = -1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (Mat[i][j] == 1) {
                LL tmp = sx[i][j] + sy[i][j] - a[i][j];
                if (tmp > ma) {
                    ma = tmp;
                    ans1.first = i, ans1.second = j;
                }
            } else {
                LL tmp = sx[i][j] + sy[i][j] - a[i][j];
                if (tmp > ma1) {
                    ma1 = tmp;
                    ans2.first = i, ans2.second = j;
                }
            }
        }
    }
    cout << ma + ma1 << endl;
    printf("%d %d %d %d\n", ans1.first, ans1.second, ans2.first, ans2.second);
}
int main()
{
    while (scanf("%d", &n) != EOF) {
        work();
    }
    return 0;
}
