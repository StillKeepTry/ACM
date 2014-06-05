/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月04日 星期三 23时40分51秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 100005
LL n, x, c[MAXN];
LL ans;
void work()
{
    ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    sort(c+1, c+1+n);
    for (int i = 1; i <= n; i ++) {
        if (x == 0) x = 1;
        ans += x * c[i];
        x --;
    }
    cout << ans << endl;
}
int main()
{
    while (cin >> n >> x) {
        work();
    }
	return 0;
}
