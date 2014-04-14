/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月10日 星期一 23时54分54秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
int n, m;
void work()
{
	if (n-1 > m || 2*n+2 < m) {
		cout << "-1" << endl;
		return ;
	} else {
		if (n-1 == m) {
			for (int i = 1; i <= n; i ++) {
				if (i == 1) cout << "0";
				else cout << "10";
			}
		} else if (n == m) {
			for (int i = 1; i <= n; i ++) {
				cout << "01";
			}
		} else {
			int t = m - n;
			for (int i = 1; i <= n; i ++) {
				cout << "1";
				if (t) {
					cout << "1";
					 t --;
				}
				cout << "0";
			}
			if (t) {
				for (int i = 1; i <= t; i ++) cout << "1";
			}
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
