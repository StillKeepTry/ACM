/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月15日 星期四 21时59分19秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005
int n, k, a[MAXN], ans, cnt;
void work()
{
    cnt = 5 - k, ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] <= cnt) ans ++;
    }
    cout << ans / 3 << endl;
}
int main()
{
    while (cin >> n >> k) {
        work();
    }
	return 0;
}
