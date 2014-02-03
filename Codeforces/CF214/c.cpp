#include <bits/stdc++.h>
#define MAXN 105
#define M1 200005
using namespace std;
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
int n, k;
const int inf = 0x13131313;
typedef pair <int, int> node;
node a[MAXN];
int w[MAXN], c[MAXN];
int dp[105][M1];
void work()
{
	memset(dp,-inf,sizeof(dp));
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].first;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].second;
		a[i].second *= k;
		w[i] = a[i].first - a[i].second; // weight
		c[i] = a[i].first;
	}
	dp[0][100000] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= 200000; j ++) {
			if (j - w[i] >= 0 && j - w[i] <= 200000) {
				dp[i][j] = Max(dp[i-1][j], dp[i-1][j - w[i]] + c[i]);
			}
		}
	}
	if (dp[n][100000] == 0) {
		cout << "-1" << endl;
	} else {
		cout << dp[n][100000] << endl;
	}
}
int main()
{
	while (cin >> n >> k) {
		work();
	}
	return 0;
}
