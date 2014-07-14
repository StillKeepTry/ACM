/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月13日 星期日 20时56分43秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 305
int p, n, x[MAXN], cnt[MAXN];
void work()
{
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; i ++) {
        int tmp = x[i] % p;
        if (cnt[tmp]) {
            printf("%d\n", i); return ;
        }
        cnt[tmp] ++;
    }
    printf("-1\n");
}
int main()
{
    while (scanf("%d %d", &p, &n) != EOF) {
        work();
    }
    return 0;
}
