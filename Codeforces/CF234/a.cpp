/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月05日 星期三 23时15分36秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a<b) a=b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a>b) a=b;}
int t, ans;
string line;
bool vis[20];
bool check(int p)
{
	for (int i = 1; i <= 12/p; i ++) {
		bool f = false;
		for (int j = 0; j < p; j ++) {
			int pos = i + j * (12 / p);
			if (vis[pos] == false) f = true;
		}
		if (!f) return true;
	}
	return false;
}
void work()
{
	for (int i = 1; i <= t; i ++) {
		cin >> line;
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < 12; i ++) {
			if (line[i] == 'X') {
				vis[i+1] = true;
			}	
		}
		ans = 0;
		vector <int> v;
		for (int i = 1; i <= 12; i ++) {
			if (12 % i) continue;
			if (check(i)) {
				ans ++;
				v.push_back(i);
			}
		}
		cout << ans << " ";
		for (int i = 0; i < v.size(); i ++) {
			cout << v[i] << "x" << (12 / v[i]) << " ";
		}
		cout << endl;
	}
}
int main()
{
	while (cin >> t) {
		work();
	}
    return 0;
}

