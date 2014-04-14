/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月17日 星期一 00时30分38秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
int t, n, p, ans;
void work()
{
	cin >> n >> p;
	ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i+1; j <= n; j ++) {
			cout << i << " " << j << endl;
			ans ++;
			if (ans >= 2 * n + p) break;
		}
		if (ans >= 2 * n + p) break;
	}
}
int main()
{
	cin >> t;
	while (t --) {
		work();
	}
    return 0;
}
