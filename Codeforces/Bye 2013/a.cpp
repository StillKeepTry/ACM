#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define X first
#define Y second
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a < b) a = b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> PII;
int a, b, ans;
void work()
{
	ans = 0;
	int cnt = 0;
	while (a) {
		ans ++;
		a --;
		cnt ++;
		if (cnt == b) {
			a ++;
			cnt = 0;
		}
	}
	cout << ans << endl;
}
int main()
{
	while (cin >> a >> b) {
		work();
	}
	return 0;
}
