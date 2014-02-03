/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月25日 星期六 00时07分40秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000006
#define LL long long
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
LL n, m, l, r, cnt = 0, a, p[MAXN];
vector<int> v;
static vector<int> vec;
static map<int, int> Map;
typedef pair <int, int> PII;
void release(int n) {
	int cnt = 0;
	while (n > 1) {
		if (p[n]) {	
			v[ (Map[p[n]]) ] ++;
			LL div = p[n];
			while (n % div == 0) {
				n /= div;
			}
		} else {
			v[ (Map[n]) ] ++;
			break;
		}
	}
}
void init()
{
	p[0] = p[1] = 1;
	for (int i = 2; i <= 10000000; i ++) {
		if (p[i]) {
			continue;
		}
		for (int j = i << 1; j <= 10000000; j += i) {
			p[j] = i;
		}
		vec.push_back(i);
		Map.insert(PII(i, vec.size()));
	}
}
void query()
{
	vector<int>::iterator first = lower_bound(vec.begin(), vec.end(), l);
	vector<int>::iterator last = upper_bound(vec.begin(), vec.end(), r);
	last --;
	if (first == vec.end() || (*first) > (*last)) {
		cout << 0 << endl;
		return ;
	}
	int L = Map[(*first)], R = Map[(*last)], ans = v[R] - v[L-1];
	cout << ans << endl;
}
void work()
{
	v.clear();
	v.assign(vec.size() + 1, 0);
	for (int i = 1; i <= n; i ++) {
		cin >> a;
		release(a);
	}
	for (int i = 1; i <= v.size(); i ++) {
		v[i] = v[i-1] + v[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> l >> r;
		query();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	init();
	while (cin >> n) {
		work();
	}
    return 0;
}
