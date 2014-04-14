/*************************************************************************
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月12日 星期六 14时58分26秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 40005
#define LL long long
int t, n, m, a[MAXN];
LL last;
int cmp(int a, int b)
{
	return a>b;
}
void work()
{
	scanf("%d %d", &n, &m);
	last = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		last += a[i];
	}
	sort (a+1, a+1+n, cmp);
	if (last <= a[1] * m) {
		printf("%d\n", a[1]);
	} else {
		last -= a[1] * m;
		if (last % m)
			cout << 1 + a[1] + last / m << endl;
		else 
			cout << a[1] + last / m << endl;
	}
}
int main()
{
	scanf("%d", &t);
	while (t --) {
		work();
	}
	return 0;
}
