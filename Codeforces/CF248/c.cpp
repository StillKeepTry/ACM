/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月31日 星期六 00时16分56秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int x, y, n, a[MAXN], dp[MAXN][MAXN], pos, val, s[MAXN], mi, ma, su;
void work()
{
    memset(s, 0, sizeof(s));
    memset(dp, 0, sizeof(dp));
    val = 0, pos = 0, su = 0;
    ma = 0, mi = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (i & 1) {
            su += a[i];
        } else {
            su -= a[i];
        }
        ma = Max(ma, su);
        mi = Min(mi, su);
        if (ma > val) {
            val = ma;
            pos = i;
        }
        s[i] = s[i-1] + a[i];
    }
    val -= mi;
    if (pos & 1) {
        x = 1;
        y = s[pos] + 1;
    } else {
        x = val;
        y = s[pos] + 1;
    }
    for (int i = pos+1; i <= n; i ++) {
        if (i & 1) {
            for (int j = 1; j <= a[i]; j ++) {
                dp[x][y] = 1;
                y ++;
                x --;
            }
            x ++;
        } else {
            for (int j = 1; j <= a[i]; j ++) {
                dp[x][y] = 2;
                y ++;
                x ++;
            }
            x --;
        }
    }
    if (pos & 1) {
        x = 1;
        y = s[pos];
    } else {
        x = val;
        y = s[pos];
    }
    for (int i = pos; i >= 1; i --) {
        if (i & 1) {
            for (int j = 1; j <= a[i]; j ++) {
                dp[x][y] = 1;
                y --;
                x ++;
            }
            x --;
        } else {
            for (int j = 1; j <= a[i]; j ++) {
                dp[x][y] = 2;
                y --;
                x --;
            }
            x ++;
        }
    }
    for (int i = 1; i <= val; i ++) {
        for (int j = 1; j <= s[n]; j ++) {
            if (dp[i][j] == 0) {
                cout << " ";
            }
            if (dp[i][j] == 1) {
                cout << "/";
            }
            if (dp[i][j] == 2) {
                cout << "\\";
            }
        }
        cout << endl;
    }
}
int main()
{
    while (cin >> n) {
        work();
    }
	return 0;
}
