/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月01日 星期六 23时21分45秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if(a<b) a=b;}
template <typename T> inline void CheckMin(T &a, T b) {if(a>b) a=b;}
int n, len, a[100];
string s;
LL ans, dp[100];
void init()
{
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 50; i ++) {
		dp[i] = dp[i-1] * 2 + 1;
	}
}
void work()
{
	cin >> s;
	int len = 0;
	ans = 0;
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'B') {
			ans ++;
			ans += dp[i];
		}
	}
	cout << ans << endl;
}
int main()
{
	init();
	while (cin >> n) {
		work();
	}
    return 0;
}
