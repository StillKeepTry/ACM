/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月08日 星期日 23时40分27秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 3005
#define X first
#define Y second
typedef pair<int, int> pii;
int n, v, pren, nown, ans, num[MAXN], tmp;
pii p[MAXN];
void work()
{
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].X >> p[i].Y;
        num[p[i].X] += p[i].Y;
    }
    ans = 0;
    for (int i = 1; i <= 3001; i ++) {
        tmp = v;
        if (i == 1) {
            pren = 0; nown = num[i];
        } else {
            pren = nown, nown = num[i];
        }
        tmp = (pren <= tmp ? tmp - pren : 0);
        int mark = tmp;
        tmp = (nown <= tmp ? tmp - nown : 0);
        nown = nown - (mark - tmp);
        ans += (v - tmp);
    }
    printf("%d\n", ans);
}
int main()
{
    while (scanf("%d %d", &n, &v) != EOF) {
        work();
    }
	return 0;
}
