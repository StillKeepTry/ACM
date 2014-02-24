/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月03日 星期一 23时29分55秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, sum, a[MAXN];
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
void work()
{
	sum = 0;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = i+1; j <= n; j ++) {
			a[i] = a[j] = gcd(a[i], a[j]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		sum += a[i];
	}
	cout << sum << endl;
}
int main()
{
	while (cin >> n) {
		work();
	}
    return 0;
}
