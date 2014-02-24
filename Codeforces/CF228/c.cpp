/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月04日 星期二 00时12分22秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, a[MAXN], b[MAXN], c[MAXN], ans;
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int getAns()
{
	for (int i = 0; i <= 100; i ++) {
		if (c[i] == 0) return i;
	}
	return 0;
}
void work()
{
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a+1, a+1+n);
	for (int i = 1; i <= n; i ++) {
		b[a[i]] ++;	
	}
	for (int i = 0; i <= 100; i ++) {
		ans = 0;
		for (int j = 0; j < b[i]; j ++) {
			c[ans] ++;		
			if (c[ans] == i+1) ans ++;
		}
	}
	cout << getAns() << endl;
}
int main()
{
	while (cin >> n) {
		work();
	}
    return 0;
}
