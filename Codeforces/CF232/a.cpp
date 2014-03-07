/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月26日 星期三 23时18分33秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 105
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline void CheckMin(T &a, T b) {if(a>b) a=b;}
template <typename T> inline void CheckMax(T &a, T b) {if(a<b) a=b;} 
int n, l, r, ans;
bool vis[MAXN];
void work()
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i ++) {
		cin >> l >> r;
		if (i == 1) {
			for (int j = l; j < r; j ++) vis[j] = true;
		} else {
			for (int j = l; j < r; j ++) vis[j] = false;
		}
	}
	ans = 0;
	for (int i = 0; i <= 100; i ++) {
		if (vis[i]) ans ++;
	}
	cout << ans << endl;
}
int main()
{
	while (cin >> n) {
		work();
	}
    return 0;
}
