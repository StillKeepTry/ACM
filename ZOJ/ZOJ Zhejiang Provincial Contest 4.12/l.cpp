/*************************************************************************
    > File Name: l.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月12日 星期六 13时39分35秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int t, n, l, ti;
string line;
typedef pair<int, int> PII;
vector <PII> v;
vector <int> ans;
bool operator < (PII a, PII b) 
{
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}
void work()
{
	v.clear(), ans.clear();
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i ++) {
		cin >> line;
		ti = (line[0] - '0') * 10 + line[1] - '1';
		ti = ti * 60 + (line[3] - '0') * 10 + line[4] - '0';
		ti = ti * 60 + (line[6] - '0') * 10 + line[7] - '0';
		v.push_back(PII(ti, i));
	}
	sort(v.begin(), v.end());
	PII now;
	for (int i = 0; i < v.size(); i ++) {
		if (i == 0) {
			now = v[i];
			ans.push_back(now.y);
		} else {
			if (now.x + l <= v[i].x) {
				ans.push_back(v[i].y);
				now = v[i];
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i ++) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}
int main()
{
	scanf("%d", &t);
	while (t --) {
		work();
	}
	return 0;
}
