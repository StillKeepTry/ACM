#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n, m;
int a[MAXN];
void work()
{
	for (int j = 1; j <= m; j ++) {
		cin >> a[j];
	}
}
int main()
{
	while (cin >> n >> m) {
		work();
	}
	return 0;
}