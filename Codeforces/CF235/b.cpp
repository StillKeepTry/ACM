/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月10日 星期一 23时39分03秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 4005
int x, k, d, num1, num2, cnt, Ma, Mi;
bool vis[MAXN];
void work()
{
	cnt = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= k; i ++) {
		cin >> d;
		if (d == 1) {
			cin >> num1 >> num2;
			vis[num1] = vis[num2] = true;
			cnt += 2;
		} else {
			cin >> num1;
			vis[num1] = true;
			cnt += 1;
		}
	}
	Mi = 0;
	for (int i = 1; i < x; i ++) {
		if (!vis[i] && !vis[i+1] && i+1 != x) {
			vis[i] = true;
			vis[i+1] = true;
			Mi ++;
		} else if (!vis[i]) {
			vis[i] = true;
			Mi ++;
		}
	}
	Ma = x - 1 - cnt;
	cout << Mi << " " << Ma << endl;
}
int main()
{
	while (cin >> x >> k) {
		work();
	}
    return 0;
}
