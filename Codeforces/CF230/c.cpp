/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月18日 星期二 21时20分20秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n, ans;
void work()
{
	ans = 0;
	if (n == 0) ans = 1;
	else if (n == 1) ans = 4;
	else {
		ans += 4 * n;
		for (LL i = 1; i <= n-1; i ++) {
			LL next = n * n - i * i;
			next = (LL)sqrt(next);
			if ((next * next + (i+1) * (i+1)) <= n*n) ans += 4;
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
