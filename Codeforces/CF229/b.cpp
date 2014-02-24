/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月11日 星期二 23时41分43秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LL long long
LL n, a[MAXN], b[MAXN], ans;
void work()
{
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];	
	}
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
	}
	ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] * 2 < b[i] || b[i] == 1) {
			ans --;
		} else {
			ans += (b[i] / 2) * (b[i] - b[i] / 2);
		}
	}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		work();
	}
    return 0;
}
