/*************************************************************************
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月06日 星期日 13时40分57秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 25
int t, n, m, a[MAXN], Sum;
void work()
{
	Sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		Sum += a[i];
	}
	if (Sum > m) {
		printf("Warning\n"); 
	} else{
		printf("Safe\n");
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
