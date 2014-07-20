/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月19日 星期六 21时01分59秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define MAXN 105
int n, m, a[MAXN], last;
void work()
{
    queue < pair<int, int> > q;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        q.push(mp(a[i], i));
    }
    while (!q.empty()) {
        pair <int, int> x = q.front();
        q.pop();
        last = x.second;
        if (x.first > m) {
            x.first -= m;
            q.push(x);
        }
    }
    printf("%d\n", last);
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF) {
        work();
    }
    return 0;
}
