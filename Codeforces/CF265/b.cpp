/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月08日 星期一 00时26分56秒
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
#define MAXN 1679616
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;

struct Point {
    LL x, y, z;
    
    Point() {}

    Point(int x, int y, int z):x(x), y(y), z(z) {}

    Point operator - (Point const a) const {
        return Point(x - a.x, y - a.y, z - a.z);
    }

    LL operator * (Point const a) const {
        return (LL)a.x * (LL)x + (LL)a.y * (LL)y + (LL)a.z * (LL)z;
    } 
} v[9], tmp[9], ans[9];

Point change(int x, int y, int z, int op) {
    if (op == 0) return Point(x, y, z);
    if (op == 1) return Point(x, z, y);
    if (op == 2) return Point(y, x, z);
    if (op == 3) return Point(y, z, x);
    if (op == 4) return Point(z, x, y);
    if (op == 5) return Point(z, y, x);
}

bool check() {
    LL len[9] = {};
    for (int i = 1; i <= 8; i ++) {
        for (int j = 1; j <= 8; j ++) {
            len[j] = (tmp[i].x - tmp[j].x) * (tmp[i].x - tmp[j].x) + (tmp[i].y - tmp[j].y) * (tmp[i].y - tmp[j].y) + (tmp[i].z - tmp[j].z) * (tmp[i].z - tmp[j].z);
        }
        sort(len + 1, len + 1 + 8);
        if (len[1] == 0 && len[3] == len[2] && len[4] == len[2] && len[5] == len[2] * 2 && len[6] == len[2] * 2 && len[7] == len[2] * 2 && len[8] == len[2] * 3) {
            continue;
        } else {
            return false;
        }
    }  
    for (int i = 1; i <= 8; i ++) {
        ans[i].x = tmp[i].x, ans[i].y = tmp[i].y, ans[i].z = tmp[i].z;
    }
    return true;
}

void work()
{
    for (int i = 2; i <= 8; i ++) {
        scanf("%lld %lld %lld", &v[i].x, &v[i].y, &v[i].z);
    }
    int cnt = 0;
    for (int i = 0; i < MAXN; i ++) {
        for (int j = 1; j <= 8; j ++) {
            tmp[j].x = v[j].x;
            tmp[j].y = v[j].y;
            tmp[j].z = v[j].z;
        }    
        int state = i;
        for (int j = 1; j <= 8; j ++) {
            int op = state % 6;
            tmp[j] = change(tmp[j].x, tmp[j].y, tmp[j].z, op);
            state /= 6;
        }
        cnt = cnt + (check() ? 1 : 0);
    }
    if (cnt >= 1) {
        printf("YES\n");
        for (int i = 1; i <= 8; i ++) {
            printf("%lld %lld %lld\n", ans[i].x, ans[i].y, ans[i].z);
        }
    } else {
        printf("NO\n"); 
    }
}
int main()
{
    while (scanf("%lld %lld %lld", &v[1].x, &v[1].y, &v[1].z) != EOF) {
        work();
    }
    return 0;
}
