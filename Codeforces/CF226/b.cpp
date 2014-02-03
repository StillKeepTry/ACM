/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月24日 星期五 23时24分04秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
string s;
#define MAXN 5005
#define LL long long
int a[MAXN][2];
LL ans, f;
void work()
{
	memset(a, 0, sizeof(a));
	ans = 0, f = -1;
	int len = s.size();
	for (int i = 0; i < len - 3; i ++) {
		string tmp = s.substr(i, 4);
		if (tmp == "bear") {
			a[i][0] = i - f;
			a[i][1] = len - i - 3;
			ans += a[i][0] * a[i][1];
			f = i;
		}
	}
	cout << ans << endl;
}
int main()
{
	while (cin >> s) {
		work();
	}
    return 0;
}
