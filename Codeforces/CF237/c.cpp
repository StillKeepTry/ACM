/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月20日 星期四 00时14分57秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define x first
#define y second
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n, k, d[MAXN], goal, du[MAXN];
bool vis[MAXN];
typedef pair<int, int> PII;
bool check()
{
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (d[i] == 0) cnt ++;
	}
	if (cnt == 1) return true;
	return false;
}
void work()
{
	memset(du, 0, sizeof(du));
	memset(vis, false, sizeof(vis));
	static vector <PII> edge;
	edge.clear();
	queue <int> que;
	static vector <PII> ans;
	ans.clear();
	for (int i = 1; i <= n; i ++) {
		cin >> d[i];
		if (d[i] == 0) {
			goal = i;
		}
	}
	if (check()) {
		for (int i = 1; i <= n; i ++) {
			edge.push_back(PII(d[i], i));
		}
		sort(edge.begin(), edge.end());
		que.push(goal);
		vis[goal] = true;
		du[goal] = 0;
		int now = 0;
		while (!que.empty()) {
			int f = que.front();
			for (;now < n; now ++) {
				if (du[f] == k) break;
				PII p = edge[now]; // this node
				if (vis[p.y]) continue;
				if (d[p.y] < d[f] + 1) {
					cout << "-1" << endl;
					return ;
				}
				if (d[p.y] != d[f] + 1) {
					break;
				}
				que.push(p.y);
				ans.push_back(PII(f, p.y));
				du[f] ++, du[p.y] ++;
				vis[p.y] = true;
			}
			que.pop();
		}
		if (now != n) {
			cout << "-1" << endl;
			return ;
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i ++) {
			PII tmp = ans[i];
			cout << Min(tmp.x, tmp.y) << " " << Max(tmp.x, tmp.y) << endl;
		}
	} else {
		cout << "-1" << endl;
	}
}
int main()
{
	while (cin >> n >> k) {
		work();
	}
    return 0;
}
