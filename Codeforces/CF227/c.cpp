/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月31日 星期五 00时16分58秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
string p;
int cnt, len, rail, a[MAXN];
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
bool check(int s, int t, int S, int T)
{
	if ((s - t) < (S - T)) return true;
	if ((s - t) > (S - T)) return false;
	for (int i = s; i <= t; i ++) {
		if (a[i] > a[i - s + S]) return true;
		if (a[i] < a[i - s + S]) return false;
	}
	return true;
}	
void work()
{
	rail = len = p.length(), cnt = 1;
	for (int i = 1; i <= len; i ++) {
		a[i] = p[i-1] - '0';
	}
	for (int i = len; i >= 1; i --) {
		if (a[i]) {
			if (check(1, i-1, i, rail)) {
				rail = i - 1;
				cnt ++;
			}		
		}
	}
	cout << cnt << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> p) {
		work();
	}
    return 0;
}
