/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月21日 星期三 23时50分42秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 105
#define LL long long
int n, k, d;
LL dp[MAXN * 2][2];
void work()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i ++) {
        for (int j = 1; j <= k; j ++) {
            if (j < d) {
                dp[i+j][0] += dp[i][0];
                dp[i+j][1] += dp[i][1];
            } else {
                dp[i+j][1] += dp[i][0];
                dp[i+j][1] += dp[i][1];
            }
            dp[i+j][0] %= MOD;
            dp[i+j][1] %= MOD;
        }
    }
    cout << (dp[n][1] % MOD) << endl;
}
int main()
{
    while (cin >> n >> k >> d) {
        work();
    }
	return 0;
}
