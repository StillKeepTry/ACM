/*************************************************************************
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月07日 星期一 00时05分30秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LL long long
template <typename T> inline T Max(T a, T b) {
	return a>b?a:b;
}
int n, k, cnt, num;
LL a[MAXN];
LL gcd(LL a, LL b) 
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
void work()
{
	cnt = n / 2;
	if (n == 1 && k > 0) {
		cout << "-1" << endl;
		return ;
	}
	if (n == 1 && k == 0) {
		cout << "1" << endl;
		return ;
	}
	if (k < cnt) {
		cout << "-1" << endl;
		return ;
	}
	a[1] = k - cnt + 1;
	a[2] = k - cnt + 1;
	a[1] *= 1;
	a[2] *= 2;
	for (int i = 3; i <= n; i ++) {
		a[i] = a[i-1] + 1;
	}
	for (int i = 1; i <= n; i ++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	while (scanf("%d %d", &n, &k) != EOF) {
		work();
	}
	return 0;
}
