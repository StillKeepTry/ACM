#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define X first
#define Y second
#define MAXN 300005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a < b) a = b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> PII;
int n;
struct node 
{
	int index;
	LL rate;
	bool operator < (const node &next) const {
		return rate < next.rate;
	}
}a[MAXN];
int b[MAXN];
void work()
{
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].rate;
		a[i].index = i;	
	}
	sort(a+1, a+1+n);
	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		LL tmp = Max(a[i].rate, ans);
		b[a[i].index] = tmp;
		ans = tmp + 1;
	}
	for (int i = 1; i <= n; i ++) {
		cout << b[i] << " ";
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


