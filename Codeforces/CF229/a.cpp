/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月11日 星期二 23时29分45秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define M 105
#define X first
#define Y second
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n, a[M][2], ans;
typedef pair <int, int> PII;
PII p[MAXN];
void work()
{
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i ++) {
		cin >> p[i].X >> p[i].Y;
		a[ p[i].X ][0] = 1;
		a[ p[i].Y ][1] = 1;
	}
	ans = 0;
	int v = 0, h = 0;
	for (int i = 0; i <= 100; i ++) {
		v += a[i][0];
		h += a[i][1];
	}
	cout << Min(v, h) << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		work();
	}
    return 0;
}
