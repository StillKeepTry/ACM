/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月06日 星期一 23时43分43秒
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
#define MOD 1000000007
#define MAXN 100005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int T, K, dp[MAXN], a, b, sum[MAXN];

int Pow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

void work()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 100000; i ++) {
        if (i < K) {
            dp[i] = 1;
        } else if (i == K) {
            dp[i] = 2;
        } else {
            dp[i] = dp[i - 1] + dp[i - K];
            dp[i] %= MOD;
        }
    }
    sum[0] = 0;
    for (int i = 1; i <= 100000; i ++) {
        sum[i] = sum[i - 1] + dp[i];
        sum[i] %= MOD;
    }
    for (int i = 1; i <= T; i ++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", (sum[b] - sum[a - 1] + MOD) % MOD);
    }
}
int main()
{
    while (scanf("%d %d", &T, &K) != EOF) {
        work();
    }
    return 0;
}
