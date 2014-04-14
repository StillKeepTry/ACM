/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月23日 星期日 00时05分51秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define LL long long
int n, a[MAXN];
bool vis[MAXN<<1] = {};
vector <int> v;
LL ans = 0;
void work()
{
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		vis[a[i]] = true;
	}
	for (int i = 1; i <= n; i ++) {
		int d = 1000000 - a[i] + 1;
		if (vis[d] == false) {
			v.push_back(d);
		} else {
			ans ++;
		}
	}
	ans /= 2;
	for (int i = 1; i <= 1000000; i ++) {
		if (ans == 0) break;
		if (vis[i] == false && vis[1000001-i] == false) {
			v.push_back(i);
			v.push_back(1000001-i);
			vis[i] = true;
			ans --;
			vis[1000001-i] = true;
		}
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i ++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}
int main()
{
	scanf("%d", &n);
	work();
    return 0;
}
