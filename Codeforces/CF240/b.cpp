/*************************************************************************
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月06日 星期日 23时47分06秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 100005
LL n, a, b, x[MAXN];
void work()
{
	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i ++) {
		LL tmp = x[i] * a % b;
		tmp = tmp / a;
		cout << tmp << " ";
	}
	cout << endl;
}
int main()
{
	while (cin >> n >> a >> b) {
		work();
	}
	return 0;
}
