/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月11日 星期二 23时57分49秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100020
int n, k, w, l, r, a[MAXN];
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
string str;
int getAns()
{
	int ans = (r - l + 1) / k;
	ans = ans - (a[r] - a[l-1]);
	for (int i = 0; i < k-1; i ++) {
		int x = r - (k-i-1), y = l - (k - i);
		if (y <= 0) y = 0;
		ans += a[x] - a[y];
	}
	return ans;
}
void work()
{
	cin >> str;
	for (int i = 0; i < n; i ++) {
		a[i+1] += (str[i] == '1' ? 1 : 0);
		a[i+k+1] = a[i+1];
	}
	for (int i = 1; i <= w; i ++) {
		cin >> l >> r;
		cout << getAns() << endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> k >> w) {
		work();
	}
    return 0;
}
