/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: d.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月17日 星期一 00时49分30秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 5005
#define NUM 100005
LL n, m, a[MAXN], b[MAXN], g[MAXN], di[MAXN];
vector<LL> prime;
bool p[NUM] = {};
int flag = 0;
LL gcd(LL a, LL b) 
{
	if (b) {
		return gcd(b, a%b);
	} 
	return a;
}
void init()
{
	for (int i = 2; i * i <= NUM; i ++) {
		if (p[i]) continue;
		for (int j = i; j * i <= NUM; j ++) {
			p[j*i] = true;
		}
		prime.push_back(i);
	}
}
void work()
{
	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (i == 1) {
			g[i] = a[i];
		} else {
			g[i] = gcd(g[i-1], a[i]);
		}
	}
	for (int i = 1; i <= m; i ++) {
		cin >> b[i];
	}
	sort (b+1, b+1+m);
	for (int i = 1; i <= n; i ++) {
		LL tmp = a[i];
		for (int j = 0; j < prime.size(); j ++) {
			if (tmp < prime[j]) break;
			while (tmp % prime[j] == 0) {
				tmp /= prime[j];
				ans ++;
			}
		}
		if (tmp > 1) ans ++;
		tmp = a[i];
		for (int j = 1; j <= m; j ++) {
			if (tmp < b[j]) break;
			while (tmp % b[j] == 0) {
				tmp /= b[j];
				ans -= 2;
			}
		}
	}
	LL d = 1;
	for (int i = n; i >= 1; i --) {
		g[i] /= d;
		LL tmp = 0, l = g[i];
		for (int j = 1; j <= m; j ++) {
			if (b[j] > g[i]) break;
			while (g[i] % b[j] == 0) {
				g[i] /= b[j];
				tmp = tmp + i;
			}
		}
		for (int j = 0; j < prime.size(); j ++) {
			if (prime[j] > g[i]) break;
			while (g[i] % prime[j] == 0) {
				g[i] /= prime[j];
				tmp -= i;
			}
		}
		if (tmp >= 0) d *= l, ans += tmp;
	}
	cout << ans << endl;
}
int main()
{
	init();
	while (cin >> n >> m) {
		work();
	}
    return 0;
}

