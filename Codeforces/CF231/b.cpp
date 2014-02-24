/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月20日 星期四 23时42分57秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 1000005
int p, x, a[MAXN];
void work()
{
	for (int i = 1; i <= 9; i ++) {
		int r = 0;		
		a[1] = i;
		for (int i = 2; i <= p; i ++) {
			a[i] = (a[i-1] * x + r) % 10; 
			r = (a[i-1] * x + r) / 10;
		}
		if ((a[p] * x + r) % 10 == a[1] && (a[p] * x + r) / 10 == 0 && a[p]) {
			for (int i = p; i >= 1; i --) {
				cout << a[i];
			}
			cout << endl;
			return ;
		}
	} 
	cout << "Impossible" << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> p >> x) {
		work();
	}
	return 0;
}
