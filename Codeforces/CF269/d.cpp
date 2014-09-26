/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月27日 星期六 00时41分17秒
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
#define MAXN 200005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, W;
LL a[MAXN], b[MAXN];
int next[MAXN];

void gao() {
    int i = 1, j = 0, dis = 0;
    next[1] = 0;
    while (i <= W && j <= W) {
        if (j == 0 || b[i] == b[j] + dis) {
            if (j == 0) {
                i ++; j ++;
                dis = b[i] - b[j];
            } else {
                i ++; j ++;
            }
            next[i] = j;
        } else {
            j = next[j];
            if (j == 1) {
                dis = b[i] - b[j];
            } else {
                dis = b[i - 1] - b[j - 1];
            }
        }
    }
}

int kmp() {
    int i = 1, j = 1;
    LL dis = a[1] - b[1];
    int ans = 0;
    while (i <= N) {
        if (j == 0 || a[i] == b[j] + dis) {
            if (j == 0) {
                i ++; j ++;
                dis = a[i] - b[j];
            } else {
                i ++; j ++;
            }
        } else {
            j = next[j];
            if (j == 1) {
                dis = a[i] - b[j];
            } else {
                dis = a[i - 1] - b[j - 1];
            }
        }
        if (j > W) {
            j = next[j]; 
            if (j == 1) {
                dis = a[i] - b[j];
            } else {
                dis = a[i - 1] - b[j - 1];
            }
            ans ++;
        }
    }
    return ans;
}

void work()
{
    for (int i = 1; i <= N; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= W; i ++) {
        cin >> b[i];
    }
    memset(next, 0, sizeof(next));
    gao();
    cout << kmp() << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> N >> W) {
        work();
    }
    return 0;
}
