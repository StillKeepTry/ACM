/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月26日 星期五 23时55分12秒
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
#define MAXN 1000005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
LL n, a[MAXN], cnt;

void init() {
    for (LL i = 1; ; i ++) {
        a[i] = (3 * i * i + i) / 2;
        if (a[i] > 1e12) {
            cnt = i - 1; break;
        }
    }
}

void work()
{
    LL ans = 0;
    for (int i = cnt; i >= 1; i --) {
        if (n >= a[i] && (n - a[i]) % 3 == 0) {
            ans ++;
        }
    }
    cout << ans << endl;
}
int main()
{
    init();
    ios::sync_with_stdio(false);
    while (cin >> n) {
        work();
    }
    return 0;
}
