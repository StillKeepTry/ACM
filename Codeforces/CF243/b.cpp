/*************************************************************************
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月27日 星期日 23时35分42秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, m, a[MAXN][MAXN], b[MAXN][MAXN];
bool check(int p)
{
	if (n % p) return false;
	int tmp = n / p;
	while ((tmp & 1) == 0) tmp /= 2;
	if (tmp != 1) return false;
	for (int i = 1; i <= p; i ++) {
		for (int j = 1; j <= m; j ++) {
			b[i][j] = a[i][j];
		}
	}
	while (p < n) {
		for (int i = 1; i <= p; i ++) {
			for (int j = 1; j <= m; j ++) {
				b[p*2 + 1 - i][j] = b[i][j];
			}
		}
		p <<= 1;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (b[i][j] != a[i][j]) return false;
		}
	}
	return true;
}
void work()
{
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (check(i)) {
			cout << i << endl;
			return ;
		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF) {
		work();
	}
	return 0;
}
