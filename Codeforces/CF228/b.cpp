/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月03日 星期一 23时51分05秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, a[MAXN][MAXN], sum;
string line;
void work()
{
	sum = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> line;
		for (int j = 1; j <= n; j ++) {
			if (line[j-1] == '#') {
				a[i][j] = 1;
				sum ++;
			} else {
				a[i][j] = 0;
			}
		}
	}
	if (sum % 5) {
		cout << "NO" << endl;
		return ;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (a[i][j]) {
				if (a[i][j] == 1 && a[i+1][j-1] == 1 &&
					a[i+1][j] == 1 && a[i+1][j+1] == 1 &&
					a[i+2][j] == 1) {
					a[i][j] = a[i+1][j-1] = a[i+1][j] = a[i+1][j+1] = a[i+2][j] = 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (a[i][j]) {
				cout << "NO" << endl;
				return ;
			}
		}
	}
	cout << "YES" << endl;
}
int main()
{
	while (cin >> n) {
		work();
	}
    return 0;
}
