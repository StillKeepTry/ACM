/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014/1/12 23:31:27
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LL long long
#pragma comment(linker, "/STACK:1024000000,1024000000") 
int m, n;
struct node {
	int type, x, l, c;
	LL len;
}a[MAXN];
int binary(LL pos)
{
	int low = 1, high = m;
	while (low < high) {
		int mid = (low + high) / 2;
		if (a[mid].len < pos) {
			low = mid + 1;
		} else if (a[mid].len > pos) {
			high = mid;
		} else {
			return mid;
		}
	}
	return low;
}
int getAns(LL pos)
{
	while (1) {
		int index = binary(pos);
		if (a[index].type == 1) {
			return a[index].x;
		} else {
			LL zlen = pos - (a[index].len - a[index].l * a[index].c);
			zlen = zlen % a[index].l;
			if (zlen == 0) {
				zlen = a[index].l;
			}
			pos = zlen;
		}
	}
}
void work()
{
	LL zlen = 0;
	for (int i = 1; i <= m; i ++) {
		cin >> a[i].type;
		if (a[i].type == 1) {
			cin >> a[i].x;
			a[i].len = ++ zlen;
		} else {
			cin >> a[i].l >> a[i].c;
			zlen += a[i].l * a[i].c;
			a[i].len += zlen;			
		}
	}
	cin >> n;
	LL tmp;
	for (int i = 1; i <= n; i ++) {
		cin >> tmp;
		cout << getAns(tmp) << " ";
	}
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> m) {
		work();
	}
	return 0;
}
