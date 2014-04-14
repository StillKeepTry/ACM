/*************************************************************************
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月12日 星期六 13时03分19秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 10
int t, n, m, sa, sb, s;
void work()
{
	scanf("%d %d", &n, &m);
	sa = sb = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &s);
		sa += s;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &s);
		sb += s;
	}
	if (sa == sb) {
		printf("Draw\n");
		return ;
	}
	if (sa > sb) {
		printf("Calem\n");
	} else {
		printf("Serena\n");
	}
}
int main()
{
	scanf("%d", &t);
	while (t --) {
		work();
	}
	return 0;
}
