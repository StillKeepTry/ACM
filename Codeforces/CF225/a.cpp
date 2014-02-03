/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014/1/20 23:02:57
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define MAXN 200005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline T CheckMin(T &a, T b) {if(a>b) a=b;}
template <typename T> inline T CheckMax(T &a, T b) {if(a<b) a=b;}
typedef pair <int, int> PII;
int n, zero;
LL ans, cnt;
int a[MAXN];
int num[MAXN] = {};
void work()
{
	ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		num[i] = num[i-1] + a[i];
	}
	zero = n - num[n];
	cnt = 0;
	for (int i = n; i >= 1; i --) {
		if (a[i] == 0) {
			cnt += num[i];
		}
	}
	ans = cnt;
	cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 1) {
			cnt += zero - (i - num[i]);
		}
	}
	ans = Min(ans, cnt);
	cout << ans << endl;
}
int main()
{
	while (cin >> n) {
		work();
	}
    return 0;
}
