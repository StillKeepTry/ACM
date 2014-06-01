/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月01日 星期日 12时55分23秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
#define MAXN 105
#define LL long long
int n, k, m, a[MAXN], b[MAXN], c[MAXN], sum;
LL dp[MAXN][MAXN], cnk[MAXN][MAXN];
string s1, s2;
void init()
{
    memset(cnk, 0, sizeof(cnk));
    cnk[0][0] = 1;
    for (int i = 1; i <= 100; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0) {
                cnk[i][j] = 1;
            } else {
                cnk[i][j] = (cnk[i-1][j-1] + cnk[i-1][j]) % MOD;
            }
        }
    }
}
void work()
{
    cin >> s1;
    cin >> s2;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i ++) {
        if (s1[i-1] == '1') {
            a[i] = 1;
        }
        if (s2[i-1] == '1') {
            b[i] = 1;
        }
    }
    sum = 0;
    for (int i = 1; i <= n; i ++) {
        c[i] = a[i] ^ b[i];
        if (c[i]) sum ++;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][sum] = 1;
    for (int i = 1; i <= k; i ++) {
        for (int j = 0; j <= n; j ++) {
            for (int k = 0; k <= j; k ++) {
                if (k <= m && (m-k <= n-j)) {
                    dp[i][j-k+m-k] = dp[i][j-k+m-k] + ((((dp[i-1][j] * cnk[j][k]) % MOD) * cnk[n-j][m-k]) % MOD);
                    dp[i][j-k+m-k] %= MOD;
                }
            }
        }
    }
    cout << (dp[k][0] % MOD) << endl;
}
int main()
{
    init();
    while (scanf("%d %d %d", &n, &k, &m) != EOF) {
        work();
    }
	return 0;
}
