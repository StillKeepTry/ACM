/*************************************************************************
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月13日 星期日 15时54分44秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second
#define MAXN 1005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
int n, k, r[MAXN], c, p, m, cnt, s;
bool vis[MAXN];
struct node {
	int c, p, v;
	node(int _c, int _p, int _v):c(_c), p(_p), v(_v) {
	}
	bool operator < (const node a) const {
		return a.p < p;
	}
};
struct node1 {
	int k, v;
	node1(int _k, int _v):k(_k), v(_v) {
	}
	bool operator < (const node1 a) const {
		return k < a.k;
	}
};
vector <node> v;
vector <node1> v1;
vector <PII> v2;
void work()
{
	v.clear(), v1.clear(), v2.clear();
	memset(vis, false, sizeof(vis));
	s = cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> c >> p;
		v.push_back(node(c, p, i));
	}
	cin >> k;
	for (int i = 1; i <= k; i ++) {
		cin >> r[i];
		v1.push_back(node1(r[i], i));
	}
	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v.size(); i ++) {
		for (int j = 0; j < v1.size(); j ++) {
			if (!vis[j] && v1[j].k >= v[i].c) {
				vis[j] = true;
				v2.push_back(PII(v[i].v, v1[j].v));
				s += v[i].p;
				cnt ++;
				break;
			}
		}
	}
	cout << cnt << " " << s << endl;
	for (int i = 0; i < v2.size(); i ++) {
		cout << v2[i].x << " " << v2[i].y << endl;
	}
}
int main()
{
	while (cin >> n) {
		work();
	}
	return 0;
}
