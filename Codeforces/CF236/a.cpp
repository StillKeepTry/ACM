/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月17日 星期一 00时00分34秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
int k, a, b, v, ans, cnt;
void work()
{
	ans = 0, cnt = 0;
	while (ans < a) {
		cnt ++;
		if (b) {
			if (b+1 >= k) {
				b = b + 1 - k;
				ans += k * v;
			} else {
				ans += v * (b + 1);
				b = 0;
			}
		} else {
			ans += v;
		}
	}
	cout << cnt << endl;
}
int main()
{
	while (cin >> k >> a >> b >> v) {
		work();
	}
    return 0;
}
