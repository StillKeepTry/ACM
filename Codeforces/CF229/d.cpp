/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: d.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月12日 星期三 00时58分56秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 60
#define x first
#define y second
int n, m, k, a[MAXN][MAXN], num;
int dir[2][2] = {{1, 0}, {0, 1}};
bool vis[MAXN][MAXN];
typedef pair<int,int> PII;
struct node
{
	int x, y, len;
	bool operator < (const node& next) const {
		return next.len < len;
	}
};
void bfs() 
{
	memset(vis, 0, sizeof(vis));
	memset(a, 0, sizeof(a));
	static queue<PII> que;
	PII p;
	p.x = 1, p.y = 1, num = 1;
	vis[1][1] = true, a[1][1] = 1;
	if (num == k) return ;
	que.push(p);
	while (!que.empty()) {
		PII now = que.front();
		for (int i = 0; i < 2; i ++) {
			PII next;
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if (next.x >= 1 && next.x <= n 
			 && next.y >= 1 && next.y <= m
			 && vis[next.x][next.y] == false) {
				que.push(next);
				vis[next.x][next.y] = true;
				a[next.x][next.y] = a[now.x][now.y] + 1;
				num ++;
				if (num == k) return ;
			}
		}
		que.pop();
	}
}
int getAns()
{
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			ans = ans + a[i][j];
		}
	}
	return ans;
}
void show(node tmp)
{
	node now;
	now.x = now.y = 1;
	for (int i = now.x; i <= tmp.x; i ++) {
		cout << "(" << i << "," << 1 << ") ";
	}
	for (int i = now.y+1; i <= tmp.y; i ++) {
		cout << "(" << tmp.x << "," << i << ") "; 
	}
	cout << endl;
}
void print()
{
	static vector <node> vec;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (a[i][j]) {
				node tmp;
				tmp.x = i, tmp.y = j, tmp.len = a[i][j];
				vec.push_back(tmp);
			}
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i ++) {
		node tmp = vec[i];
		show(tmp);
	}
}
void work()
{
	memset(a, 0, sizeof(a));
	bfs();
	cout << getAns() << endl;
	print();
}
int main()
{
	while (cin >> n >> m >> k) {
		work();
	}
    return 0;
}
