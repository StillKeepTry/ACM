/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月23日 星期日 14时06分55秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define x first
#define y second
int n, m, a[5], ans[MAXN][MAXN];
string str;
typedef pair <int, int> PII; 
void work()
{
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> str;		
			if (str == "00") a[0] ++;
			if (str == "01" || str == "10") a[1] ++;
			if (str == "11") a[2] ++;
		}
	}
	PII now = PII(0,0);
	for (int i = 1; i <= a[2]; i ++) {
		if (i == 1) {
			now.x = 1, now.y = 1;
			ans[now.x][now.y] = 2;
		} else {
			now.y ++;
			if (now.y > m) now.y = 1, now.x ++;
			ans[now.x][now.y] = 2;
		}
	}
	int zero = 1;
	for (int i = 1; i <= a[1]; i ++) {
		if (zero > 0) {
			if (now.x == 0 && now.y == 0) {
				now.x = now.y = 1;
				ans[now.x][now.y] = zero;
			} else {
				now.y ++;
				if (now.y > m) {
					zero = -zero;
					now.x ++, now.y = m;
					ans[now.x][now.y] = zero;
				} else {
					ans[now.x][now.y] = zero;
				}
			}
		} else {
			if (now.x == 0 && now.y == 0) {
				now.x = now.y = 1;
				ans[now.x][now.y] = zero;
			} else {
				now.y --;
				if (now.y > 0) {
					ans[now.x][now.y] = zero;
				} else {
					zero = -zero;
					now.x ++, now.y = 1;
					ans[now.x][now.y] = zero;
				}
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (ans[i][j] == 0) cout << "00 "; 
			if (ans[i][j] == 1) cout << "01 ";
			if (ans[i][j] == -1) cout << "10 ";
			if (ans[i][j] == 2) cout << "11 ";
		}
		cout << endl;
	}
}
int main()
{
	while (cin >> n >> m) {
		work();
	}
    return 0;
}
