/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月17日 星期四 21时47分12秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
LL n, m, k;

bool check(LL x)
{
    LL cnt = 0;
    for (int i = 1; i <= n; i ++) {
        cnt += Min(m, x / i);
    }
    return cnt >= k;
}

void work()
{
    LL l = 1, r = n * m;
    while (r - l >= 1) {
        LL mid = (r + l) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}
int main()
{
    while (cin >> n >> m >> k) {
        work();
    }
    return 0;
}
