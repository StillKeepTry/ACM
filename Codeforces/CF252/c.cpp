/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月08日 星期日 23时55分06秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define X first 
#define Y second
#define pb push_back
typedef pair<int, int> pii;
typedef vector <pii> vi;
int n, m, k, cnt, x, y, num, dir;
vi a[MAXN];
void work()
{
    cnt = n * m / k, num = n * m;
    for (int i = 1; i <= n * m; i ++) a[i].clear();
    x = 1, y = 1, dir = 1;
    for (int i = 1; i < k; i ++) {
        for (int j = 1; j <= 2; j ++) {
            a[i].pb(pii(x, y));
            num --;
            if (dir == 1) {
                y ++;
                if (y > m) y = m, dir = 2, x ++;
            } else if (dir == 2) {
                y --;
                if (y < 1) y = 1, dir = 1, x ++;
            }
        }
    }
    for (int i = 1; i <= num; i ++) {
        a[k].pb(pii(x, y));
        if (dir == 1) {
            y ++;
            if (y > m) y = m, dir = 2, x ++;
        } else {
            y --;
            if (y < 1) y = 1, dir = 1, x ++;
        }
    }
    for (int i = 1; i <= k; i ++) {
        cout << a[i].size();
        for (int j = 0; j < a[i].size(); j ++) {
            cout << " " << a[i][j].X << " " << a[i][j].Y;
        }
        cout << endl;
    }
}
int main()
{
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        work();
    }
	return 0;
}
