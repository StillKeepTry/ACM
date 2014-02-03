/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月30日 星期四 23时50分38秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 3005
int a[MAXN], b[MAXN], n, m, pos, cnt;
void work()
{
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= m; i ++) cin >> b[i];
	sort(a+1, a+1+n);
	sort(b+1, b+1+m);
	pos = 1, cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] <= b[pos]) {
			pos ++; cnt ++;
		} else {
			while (a[i] > b[pos] && pos <= m) {
				pos ++;
			}
			if (pos > m) break;
			cnt ++; pos ++;
		}
	}
	cout << n - cnt << endl;
}
int main()
{
	while (cin >> n >> m) {
		work();
	}
    return 0;
}
