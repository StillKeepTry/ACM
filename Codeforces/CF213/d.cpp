#include <bits/stdc++.h>
#define LL long long
#define eps 1e-8
#define MAXN 55
using namespace std;
template<typename T> inline T Max(T a, T b) {return a>b?a:b;}
template<typename T> inline T Min(T a, T b) {return a<b?a:b;}
template<typename T> inline void checkMax(T &a, T b) {if (a < b) a = b;}
template<typename T> inline void checkMin(T &a, T b) {if (a > b) a = b;}
template<typename T> inline T Abs(T a) {return a>0?a:-a;}
const int inf = 0x13131313;
int n, d;
int c[MAXN];
int Mat[MAXN][MAXN];
void work()
{
	c[0] = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
	}
	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= n; j ++) {
			if (i == j) continue;
			if (c[i] + d < c[j]) continue;
			Mat[i][j] = c[j] - c[i];
		}
	}

}
int main()
{
	while (cin >> n >> d) {
		work();
	}
	return 0;
}