#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n, m, p, mark, cnt;
int a[MAXN], b[MAXN];
int num[MAXN];
map <int, int> ma;
vector <int> ans;
int cmp(int a, int b) 
{
	return a<b;
}
void work()
{
	mark = 1;
	memset(num,0,sizeof(num));
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	ma.clear();
	for (int i = 1; i <= m; i ++) {
		cin >> b[i];
		if (ma[b[i]] == 0) {
			ma[b[i]] = mark;
			num[mark] ++;
			mark ++;
		} else {
			int key = ma[b[i]];
			num[key] ++;
		}
	}
	ans.clear();
	for (int i = 1; i <= p; i ++) {
		queue <int> que;
		for (int j = 0; (j*p+i) <= n; j ++) {
			int in = i + j*p;
			//que.push(a[in]);
			if (ma[a[in]] == 0) {
				while (!que.empty()) {
					int top = que.front();
					num[ma[top]] ++;
					que.pop();
				}
				continue;
			} else {
				que.push(a[in]);
				int key = ma[a[in]];
				num[key] --;
				if (num[key] < 0) {
					while (num[key] != 0) {
						int top = que.front();
						num[ma[top]] ++;
						que.pop();
					}
				}
				if (que.size() == m) {
					in = in - (m-1) * p;
					ans.push_back(in);
					int top = que.front();
					num[ma[top]] ++;
					que.pop();
				}
			}
		}
		while (!que.empty()) {
			int top = que.front();
			num[ma[top]] ++;
			que.pop();
		}
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i ++) {
		// cout << ans[i] << " ";
		if (i == 0) cout << ans[i];
		else cout << " " << ans[i];
	}
	cout << endl;
}
int main() 
{
	while (cin >> n >> m >> p) {
		work();
	}
	return 0;
}