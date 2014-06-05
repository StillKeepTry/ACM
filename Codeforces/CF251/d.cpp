/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月05日 星期四 00时14分58秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
LL n, m, a[MAXN], b[MAXN], sum[MAXN], add[MAXN], ans, s;
void work()
{
    memset(add, 0, sizeof(add));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }   
    sort (a+1, a+1+n);
    for (int i = 1; i <= n; i ++) {
        add[i] = add[i-1] + a[i];
    }
    for (int i = 1; i <= m; i ++) {
        cin >> b[i];
    }
    sort(b+1, b+1+m);
    for (int i = 1; i <= m; i ++) {
        sum[i] = sum[i-1] + b[i];
    }
    ans = 1e18;
    for (int i = 1; i <= n; i ++) {
        int index = lower_bound(b+1, b+1+m, a[i]) - b - 1;
        LL tmp = a[i] * (i-1) - add[i-1] + sum[m] - sum[index] - a[i] * (m - index);
        ans = Min(tmp, ans);
    }
    for (int i = 1; i <= m; i ++) {
        int index = lower_bound(a+1, a+1+n, b[i]) - a - 1;
        LL tmp = sum[m] - sum[i] - b[i] * (m - i) + b[i] * index - add[index];
        ans = Min(tmp, ans);
    }
    cout << ans << endl;
}
int main()
{
    while (cin >> n >> m) {
        work();
    }
	return 0;
}
