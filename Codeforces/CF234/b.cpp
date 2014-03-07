/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月05日 星期三 23时17分30秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a<b) a=b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a>b) a=b;}
int n, m, g, s;
string line;
void work()
{
	set <int> s1;
	bool flag = true;
	for (int i = 1; i <= n; i ++) {
		cin >> line;
		for (int j = 0; j <= m; j ++) {
			if (line[j] == 'G') {
				g = j;
			} else if (line[j] == 'S') {
				s = j;
			}
		}
		if (g > s) flag = false;
		else s1.insert(s-g);
	}
	if (!flag) {
		cout << -1 << endl;
	} else {
		cout << s1.size() << endl;
	}
}
int main()
{
	//freopen("in", "r", stdin);
	while (cin >> n >> m) {
		work();
	}
    return 0;
}
