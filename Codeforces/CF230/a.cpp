/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月18日 星期二 21时00分32秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define Max(a,b) (a)>(b)?(a):(b)
string str;
int a[100], ans;
void work()
{
	memset(a, 0, sizeof(a));
	for (int i = 0; i <= str.length(); i ++) {
		if (str[i] == 'n') a[0] ++;
		if (str[i] == 'i') a[1] ++;
		if (str[i] == 'e') a[2] ++;
		if (str[i] == 't') a[3] ++;
	}
	ans = 0;
	a[0] -= 3, a[1] -= 1, a[2] -= 3, a[3] -= 1;
	while (a[0] >= 0 && a[1] >= 0 && a[2] >= 0 && a[3] >= 0) {
		ans ++;
		a[0] -= 2, a[1] -= 1, a[2] -= 3, a[3] -= 1;
	}
	cout << ans << endl;
}
int main()
{
	while (cin >> str) {
		work();
	}
    return 0;
}
