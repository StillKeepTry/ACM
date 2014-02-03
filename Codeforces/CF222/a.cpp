#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a<b) a=b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a>b) a=b;}
int n, m, k, cnt;
string line;
int maze[MAXN][MAXN];
pair <int, int> start;
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
struct node 
{
	int x, y;
};
void Set(node a) 
{
	maze[a.x][a.y] = 2;
}
void bfs(int div)
{
	if (div == 0) return ;
	node a;
	div --;
	a.x = start.first, a.y = start.second;
	Set(a);
	queue<node> que;
	que.push(a);
	while (!que.empty()) {
		if (div == 0) return ;
		node tmp = que.front();
		for (int i = 0; i < 4; i ++) {
			node next;
			next.x = tmp.x + dir[i][0];
			next.y = tmp.y + dir[i][1];
			if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m && maze[next.x][next.y] == 0) {
				Set(next);
				que.push(next);
				div --;
			}
			if (div == 0) return ;
		}
		que.pop();
	}
}
void work() 
{
	memset(maze, 0, sizeof(maze));
	cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> line;
		for (int j = 0; j < m; j ++) {
			if (line[j] == '#') {
				maze[i][j+1] = 1;
				cnt ++;
			}
		}
	}
	int div = n * m - cnt, flag = 0;
	div -= k;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (maze[i][j] == 0) {
				start = make_pair(i,j);
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	bfs(div);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (maze[i][j] == 0) {
				cout << 'X';
			} else if (maze[i][j] == 1) {
				cout << '#';
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> k) {
		work();
	}
	return 0;
}
