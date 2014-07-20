/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月19日 星期六 21时21分13秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
LL n, m, k, ans;
void work()
{
    if ((n - 1) + (m - 1) < k) {
        cout << -1 << endl;
    } else {
        ans = 0;
        if ((n - 1) >= k || (m - 1) >= k) {
            if ((n - 1) >= k) {
                ans = Max(ans, m * (n / (k + 1)));
            }
            if ((m - 1) >= k) {
                ans = Max(ans, n * (m / (k + 1)));
            }
            cout << ans << endl;
            return ;
        } else {
            ans = Max(m / (k - n + 2), n / (k - m + 2));
            cout << ans << endl;
        }

    }
}
int main()
{
    while (cin >> n >> m >> k) {
        work();
    }
    return 0;
}
