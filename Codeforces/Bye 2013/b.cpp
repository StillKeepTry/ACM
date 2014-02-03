#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define X first
#define Y second
#define MAXN 305
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a < b) a = b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> PII;
int n;
LL a[MAXN];
void work()
{
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) {
		if (!i) {
			for (int j = 0; j < a[i]; j ++) {
				cout << "PRL";
			}
		} else {
			for (int j = 0; j < a[i]; j ++) {
				cout << "PLR";
			}
		}
		if (i != n-1) cout << "R";
	}
	cout << endl;
}
int main()
{
	while (cin >> n) {
		work();
	}
	return 0;
}

