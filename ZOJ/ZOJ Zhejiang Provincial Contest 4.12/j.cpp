/*************************************************************************
    > File Name: j.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月12日 星期六 14时31分40秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define LL long long
int t;
string s[] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};
LL n, n1, n2, cnt, num[10], ans, seven[10];
void init()
{
	for (int i = 1; i <= 7; i ++) {
		LL tmp = 1;
		for (int j = 1; j <= i; j ++) {
			tmp *= i;
		}
		num[i] = tmp % 7;
		tmp = 1;
		for (int j = 1; j <= 7; j ++) {
			tmp *= i;
		}
		seven[i] = tmp % 7;
	}
}
LL cal(LL a, LL b)
{
	LL ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % 7;
		a = a * a % 7;
		b >>= 1;
	}
	return ans;
}
void work()
{
	cin >> n;
	n1 = n / 7, n2 = n % 7;
	ans = 0;
	for (int i = 1; i <= 6; i ++) {
		if (i <= n2) {
			cnt = n1 + 1;
		} else {
			cnt = n1;
		}
		if (seven[i] == 1) {
			ans = ans + cnt * num[i] % 7;
		} else {
			ans = ans + num[i] * (cal(seven[i], cnt) - 1) % 7 * cal(seven[i] - 1, 5) % 7;
		}
	}
	ans = (6 + ans) % 7; 
	cout << s[ans] << endl;
}
int main()
{
	init();
	scanf("%d", &t);
	while (t --) {
		work();
	}
	return 0;
}
