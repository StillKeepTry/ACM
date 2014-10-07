/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月07日 星期二 00时05分37秒
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
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const int INF = 0x3fffffff;
int N, ans;

struct Point {
    int x, y;
    
    Point() {}

    Point(int _x, int _y):x(_x), y(_y) {}

    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    } 

    Point Rotate() {
        return Point(-y, x);
    }
};

struct Node {
    Point a, b;
} p[5];

Point tmp[5];

bool check() {
    vector <LL> now;
    for (int i = 1; i <= 4; i ++) {
        for (int j = i + 1; j <= 4; j ++) {
            now.pb((LL)(tmp[j].x - tmp[i].x) * (tmp[j].x - tmp[i].x) + (LL)(tmp[j].y - tmp[i].y) * (tmp[j].y - tmp[i].y));
        }
    }
    sort(now.begin(), now.end());
    if (now[0] == 0) return false;
    if (now[0] == now[1] && now[0] == now[2] && now[0] == now[3] && now[0] * 2 == now[4] && now[0] * 2 == now[5]) {
        return true;
    }
    return false;
}

void gao() {
    for (int i = 0; i < 4 * 4 * 4 * 4; i ++) {
        for (int j = 1; j <= 4; j ++) {
            tmp[j] = p[j].a;
        }
        int now = i, maxlen = 0;
        for (int j = 1; j <= 4; j ++) {
            int d = now % 4;
            maxlen += d;
            for (int k = 0; k < d; k ++) {
                tmp[j] = (tmp[j] - p[j].b).Rotate() + p[j].b;
            }
            now /= 4;
        }
        if (check()) ans = Min(ans, maxlen);
    }
}

void work()
{
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= 4; j ++) {
            scanf("%d %d %d %d", &p[j].a.x, &p[j].a.y, &p[j].b.x, &p[j].b.y);
        }
        ans = INF;
        gao();
        if (ans == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }
}
int main()
{
    while (scanf("%d", &N) != EOF) {
        work();
    }
    return 0;
}
