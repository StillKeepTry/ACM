/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月24日 星期五 23时23分51秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 106
#define Max(a,b) (a)>(b)?(a):(b)
int n, c, ans;
int a[MAXN];
void work()
{
	ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	a[n+1] = 0x13131313;
	for (int i = 1; i <= n; i ++) {
		ans = Max(ans, a[i] - a[i+1]);
	}
	ans = Max(ans - c, 0);
	cout << ans << endl;
}
int main()
{
	while (cin >> n >> c) {
		work();
	}
    return 0;
}

