#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define X first
#define Y second
#define MAXN 55
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a < b) a = b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> PII;
LL k, x, n, m;
LL div1;
LL fibo[4][MAXN] = {};
LL dp[4][MAXN] = {};
void init() 
{
	fibo[1][1] = 1;
	fibo[1][2] = 0;
	fibo[2][1] = 0;
	fibo[2][2] = 1;
	dp[1][3] = 1;
	for (int i = 3; i <= 50; i ++) {
		fibo[1][i] = fibo[1][i-1] + fibo[1][i-2];
		fibo[2][i] = fibo[2][i-1] + fibo[2][i-2];
		if (i >= 4) {
			dp[1][i] = dp[1][i-2] + dp[1][i-1];
			dp[2][i] = dp[2][i-2] + dp[2][i-1];
			dp[3][i] = dp[3][i-2] + dp[3][i-1];
			if (i & 1) {
				dp[3][i] ++;
			} else {
				dp[2][i] ++;
			}
		}
	}
}
LL gcd(LL a, LL b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	LL d = exgcd(b, a%b, x, y), t = x;
	x = y;
	y = t - (a/b) * y;
	return d;
}
bool fun1(LL x, LL &a1, LL &a2)
{
	if (x % div1) return false;
	exgcd(fibo[1][k], fibo[2][k], a1, a2);
	return true;
}
void work()
{
	LL a1, a2;
	div1 = gcd(fibo[1][k], fibo[2][k]);
	for (int i = 0; i < 16; i ++) {
		LL tmp = x;
		if (i & 6 == 6) {
			tmp -= dp[1][k];
		}	
		if (i & 9 == 9) {
			tmp -= dp[2][k];
		}
		if (i & 3 == 3) {
			tmp -= dp[3][k];
		}
		if (fun1(tmp, a1, a2)) {
			int d = 0;
			if (i & 8 == 8) {
				d ++;
			}
			if (i & 4 == 4) {
				d ++;
			}
			if (a1 * 2 + d > n) continue;

			int e = 0;
			if (i & 2 == 2) {
				e ++;
			}
			if (i & 1 == 1) {
				e ++;
			}
			if (a2 * 2 + e > m) continue;
			if (i & 8 == 8) {
				cout << "C";
			}
			for (int j = 0; j < a1; j ++) cout << "AC";
			for (int j = a1*2; j < n-1; j ++) cout << "D";
			if (i & 4 == 4) {
				cout << "A";
			} else {
				cout << "D";
			}
			cout << endl;
			if (i & 2 == 2) {
				cout << "C";
			}
			for (int j = 0; j < a2; j ++) cout << "AC";
			for (int j = a2*2; j < m-1; j ++) cout << "D";
			if (i & 1 == 1) {
				cout << "A";
			} else {
				cout << "D";
			}
			cout << endl;
			return ;
		}
	}
	cout << "Happy new year!" << endl;
}
int main()
{
	init();
	while (cin >> k >> x >> n >> m) {
		work();
	}
	return 0;
}



