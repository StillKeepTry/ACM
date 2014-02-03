#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n, k, lastAns, index;
const int inf = 0x13131313;
vector <int> vec(MAXN);
vector <int> ans(MAXN);
void work()
{
	for (int i = 1; i <= n; i ++) {
		cin >> vec[i];
		int tmp = ans[i % k];
		tmp += vec[i];
		ans[i % k] = tmp;
	}
	ans[k] = ans[0];
	lastAns = inf;
	for (int i = 1; i <= k; i ++) {
		if (lastAns > ans[i]) {
			lastAns = ans[i];
			index = i;
		}
	}
	cout << index << endl;
}
int main()
{
	while (cin >> n >> k) {
		work();
	}
	return 0;
}