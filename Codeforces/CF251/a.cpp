/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月04日 星期三 23时30分13秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
int n, d, t[MAXN], num, cnt;
void work()
{
    num = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &t[i]);
        num += (t[i] + 10);
    }
    num -= 10;
    cnt = (n-1) * 2;
    if (num > d) {
        printf("-1\n");
    } else {
        num = d - num; 
        cnt += num / 5;
        printf("%d\n", cnt);
    }
}
int main()
{
    while (scanf("%d %d", &n, &d) != EOF) {
        work();
    }
	return 0;
}
