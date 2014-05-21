/*************************************************************************
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年05月11日 星期日 23时58分17秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define pb push_back
template <typename T> inline T Max(T a, T b) {
	return a>b?a:b;
}
typedef vector<int> vi;
int n, k, x, c[MAXN], ans;
int solve(vi v)
{
	int pre = v.size();
	for (int i = 1; i <= n; i ++) {
		vi next;
		int cnt, num;
		for (int j = 0; j < v.size(); j ++) {
			if (j == 0) {
				cnt = v[j], num = 1;
			} else {
				if (v[j] == v[j-1]) {
					num ++;
				} else {
					if (num <= 2) {
						for (int k = 1; k <= num; k ++) next.pb(cnt);
					}
					cnt = v[j], num = 1;
				}
			}
		}
		if (num <= 2) {
			for (int k = 1; k <= num; k ++) next.pb(cnt);
		}
		v = next;
	}
	int now = v.size();
	return pre - now;
}
void work()
{
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
	}
	ans = 0;
	for (int i = 1; i <= n+1; i ++) {
		vi v;
		for (int j = 1; j <= n; j ++) {
			if (j == i) {
				v.pb(x); v.pb(c[j]);
			} else {
				v.pb(c[j]);
			}
		}
		if (i == n+1) v.pb(x);
		ans = Max(ans, solve(v));
	}
	if (ans > 0) ans --;
	cout << ans << endl;
}
int main()
{
	while (cin >> n >> k >> x) {
		work();
	}
	return 0;
}
