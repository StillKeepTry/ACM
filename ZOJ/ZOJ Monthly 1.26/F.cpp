/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月26日 星期日 13时44分07秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n;
LL ans = 0;
void work()
{
	ans = (n - 1) * (n * n + n * n - 2 * n + 4) / 2;
	if (n & 1) {
		ans += 1;
		while (n > 1) {
			ans += 2 * (n-2);
			n -= 2;
		}
	} else {
		ans += 2;
		while (n) {
			ans += 2 * (n-2);
			n -= 2;
		}
	}
	cout << ans << endl;
}
int main()
{
	while (cin >> n) {
		work();
	}
    return 0;
}
