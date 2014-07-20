/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月19日 星期六 21时06分29秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
#define N 3
LL x, y, n, ans[N][N], a[N][N];

void product_mod(LL a[][N], LL b[][N])
{
    LL c[N][N] = {};
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 2; j ++) {
            for (int k = 0; k < 2; k ++) {
                c[i][j] += (a[i][k] * b[k][j] % MOD);
            }
            c[i][j] %= MOD;
        }
    }
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 2; j ++) {
            a[i][j] = c[i][j];
        }
    }
}

void power_mod(LL a[][N], LL x)
{
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < 2; i ++) {
        ans[i][i] = 1;
    }
    while (x) {
        if (x & 1) product_mod(ans, a);
        product_mod(a, a);
        x >>= 1;
    }
}

void work()
{
    cin >> n;
    x = (x + MOD) % MOD;
    y = (y + MOD) % MOD;
    if (n == 1) {
        cout << (x % MOD) << endl;
    } else if (n == 2) {
        cout << (y % MOD) << endl;
    } else {
        a[0][0] = 1, a[0][1] = (-1 + MOD) % MOD;
        a[1][0] = 1, a[1][1] = 0;
        power_mod(a, n-2);
        LL res = (ans[0][0] * y % MOD) + (ans[0][1] * x % MOD);
        res = res % MOD;
        cout << res << endl;
    }
}
int main()
{
    while (cin >> x >> y) {
        work();
    }
    return 0;
}
