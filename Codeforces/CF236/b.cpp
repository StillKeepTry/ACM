/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月17日 星期一 00时05分44秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
int n, k, a[MAXN], b[MAXN], ans, d;
void work()
{
    static map<int, int> Map;
    Map.clear();
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (i == 1) {
            b[i] = a[i];
        } else {
            b[i] = b[i-1] + k;
        }
        int dis = b[i] - a[i];
        Map[dis] ++;
    }
    ans = 0x13131313;
    for (map<int, int>::iterator it = Map.begin(); it != Map.end(); it ++) {
        int x = it->first, y = it->second;
        y = n - y;
        if (a[1] - x <= 0) continue; 
        if (y < ans) {
            ans = y;
            d = x;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i ++) b[i] = b[i] - a[i] - d;
    for (int i = 1; i <= n; i ++) {
        if (b[i] > 0) {
            cout << "+" << " " << i << " " << b[i] << endl;
        } else if (b[i] < 0) {
            cout << "-" << " " << i << " " << (-b[i]) << endl;
        }
    }
}
int main()
{
   // freopen("in", "r", stdin);
    while (cin >> n >> k) {
        work();
    }
    return 0;
}

