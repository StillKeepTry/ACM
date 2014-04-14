/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月19日 星期三 23时32分05秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 303
int n;
string line;
int a[MAXN][MAXN];
int check1()
{
	int num = a[1][1];
	for (int i = 1; i <= n; i ++) {
		if (a[i][i] != num) return -1;
	}
	for (int i = 1; i <= n; i ++) {
		if (a[n-i+1][i] != num) return -1;
	}
	return a[1][1];
}
int check2()
{
	int flag = 0, num = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i != j && i + j != n + 1) {
				if (flag == 0) {
					num = a[i][j];
					flag = 1;
				} else {
					if (a[i][j] != num) return -1;
				}
			}
		}
	}
	return num;
}
void work()
{
	for (int i = 1; i <= n; i ++) {
		cin >> line;
		for (int j = 0; j < n; j ++) {
			a[i][j+1] = line[j];
		}
	}
	int m1 = check1(), m2 = check2();
	if (m1 >= 0 && m2 >= 0 && m1 != m2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main()
{
	while (cin >> n) {
		work();
	}
    return 0; 
}
