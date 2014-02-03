#include <bits/stdc++.h>
using namespace std;
int n;
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair < pair <int, int>, pair<int, int> > node;
node f[4];
void work()
{
	for (int i = 0; i < 4; i ++) {
		cin >> f[i].first.first >> f[i].first.second >> f[i].second.first >> f[i].second.second;
	}
	for (int i = 0; i < 4; i ++) {
		if (Min(f[i].first.first, f[i].first.second) + Min(f[i].second.first, f[i].second.second) <= n) {
			int a = Min(f[i].first.first, f[i].first.second);
			printf("%d %d %d\n", i+1, a, n - a);
			return ;
		}
	}
	printf("-1\n");
}
int main()
{
	while (cin >> n) {
		work();
	}
	return 0;
}