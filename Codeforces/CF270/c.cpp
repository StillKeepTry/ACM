/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月28日 星期日 23时45分32秒
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
typedef pair<string, string> Pss;
int N, p[MAXN];
Pss name[MAXN];

void work()
{
    for (int i = 1; i <= N; i ++) {
        cin >> name[i].x >> name[i].y;
        if (name[i].x > name[i].y) {
            swap(name[i].x, name[i].y);
        }
    }
    for (int i = 1; i <= N; i ++) {
        cin >> p[i];
    }
    string pre = "", now;
    for (int i = 1; i <= N; i ++) {
        if (i == 1) {
            now = name[p[i]].x;
        } else {
            if (name[p[i]].x > pre) {
                now = name[p[i]].x;
            } else {
                if (name[p[i]].y > pre) {
                    now = name[p[i]].y;
                } else {
                    printf("NO\n"); return ;
                }
            }
        }
        swap(now, pre);
    }
    printf("YES\n");
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> N) {
        work();
    }
    return 0;
}
