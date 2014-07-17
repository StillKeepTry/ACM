/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月17日 星期四 21时32分46秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 5005
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
LL n, a[MAXN], ans, dp[MAXN][MAXN];

LL gao(int l, int r, int h)
{
    if (l > r) return 0;
    int pos = l;
    for (int i = l+1; i <= r; i ++) {
        if (a[i] < a[pos]) pos = i;
    }
    LL res = gao(l, pos-1, a[pos]) + gao(pos+1, r, a[pos]) + a[pos] - h;
    return Min((LL)(r-l+1), res);
}

void work()
{
    ans = n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    cout << gao(1, n, 0) << endl;
}
int main()
{
    while (cin >> n) {
        work();
    }
    return 0;
}
