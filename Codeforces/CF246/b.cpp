/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月15日 星期四 23时49分08秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n, x[MAXN], y[MAXN], a[MAXN], b[MAXN];
void work()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
        a[x[i]] ++;
        b[y[i]] ++;
    }
    for (int i = 1; i <= n; i ++) {
        int a1 = n - 1 + a[y[i]];
        int a2 = n - 1 - a[y[i]];
        cout << a1 << " " << a2 << endl;
    }
}
int main()
{
    while (cin >> n) {
        work();
    }
	return 0;
}
