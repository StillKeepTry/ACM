/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月22日 星期四 00时22分34秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 205
LL m, k, n, dp[MAXN][MAXN], a[MAXN][MAXN];
void init()
{
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1, dp[1][1] = 1;
    for (int i = 2; i <= 64; i ++) {
        for (int j = 1; j < i; j ++) {
            for (int k = 0; k <= 64; k ++) {
                dp[i][k+1] += dp[j][k];
            }
        }
    }
}
LL calc(LL n)
{
    LL ans = 0, cnt = 0;
    for (LL i = 63; i >= 0; i --) {
        if (n & (1ll << i)) {
            if (k > cnt) {
                for (int j = 0; j <= i; j ++) {
                    ans += dp[j][k-cnt];
                }
            }
            cnt ++;
            if (cnt == k) {
                ans ++;
            }
        }
    }
    return ans;
}
void work()
{
    LL low = 1, high = 1e18;
    while (low < high) {
        LL mid = (low + high) / 2;
        LL tmp = calc(mid*2) - calc(mid);
        if (tmp == m) {
            cout << mid << endl;
            return ;
        }
        if (tmp < m) {
            low = mid+1;
        } else {
            high = mid;
        }
    }
}
int main()
{
    init();
    while (cin >> m >> k) {
        work();
    }
	return 0;
}
