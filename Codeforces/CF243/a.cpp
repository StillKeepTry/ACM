/*************************************************************************
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月27日 星期日 23时30分23秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, s, a[MAXN], ans;
void work()
{
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	ans = 0;
	for (int i = 1; i < n; i ++) {
		ans += a[i];
	}
	if (ans <= s) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main()
{
	while (cin >> n >> s) {
		work();
	}
	return 0;
}
