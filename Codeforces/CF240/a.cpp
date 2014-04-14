/*************************************************************************
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月06日 星期日 23时39分34秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, m, b[MAXN], a[MAXN];
void work()
{
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= m; i ++) {
		cin >> b[i];
		for (int j = b[i]; j <= n; j ++) {
			if (a[j] == 0) {
				a[j] = b[i];
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	while (cin >> n >> m) {
		work();
	}
	return 0;
}
