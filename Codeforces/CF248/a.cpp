/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月30日 星期五 23时29分24秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, m, a[MAXN], cnt, ans, num;
void work()
{
    num = 0, ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        num += a[i];
        if (num > m) {
            ans ++;
            num = a[i];
        }
    }
    if (num) {
        ans ++;
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
