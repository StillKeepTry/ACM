/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月08日 星期五 23时31分35秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
#define MAXN 100005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n, a[MAXN];
LL ans, num[MAXN], dp[MAXN][2];

void work()
{
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    LL a1, a2;
    a1 = a2 = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        num[a[i]] ++;
    }
    for (int i = 1; i <= 100000; i += 2) {
        a1 = a1 + num[i] * (LL)i;
    }
    for (int i = 2; i <= 100000; i += 2) {
        a2 = a2 + num[i] * (LL)i;
    }
    for (int i = 1; i <= 100000; i ++) {
        if (i == 1) {
            dp[i][0] = 0;
            dp[i][1] = num[i];
        } else if (i == 2) {
            dp[i][0] = num[1];
            dp[i][1] = num[2] * 2;
        } else {
            dp[i][0] = Max(dp[i-1][1], dp[i-2][0]);
            dp[i][0] = Max(dp[i][0], dp[i-2][1]);
            dp[i][0] = Max(dp[i][0], dp[i-1][0]);
            dp[i][1] = Max(dp[i-1][0], dp[i-2][1]);
            dp[i][1] = Max(dp[i][1], dp[i-2][0]);
            dp[i][1] += num[i] * i;
        }
    }
    cout << Max(dp[100000][0], dp[100000][1]) << endl;
}
int main()
{
    while (scanf("%d", &n) != EOF) {
        work();
    }
    return 0;
}
