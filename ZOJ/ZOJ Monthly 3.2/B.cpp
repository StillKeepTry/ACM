/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月02日 星期日 12时01分34秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if (a<b) a=b;}
template <typename T> inline void CheckMin(T &a, T b) {if (a>b) a=b;}
int n, b;
LL getP()
{
	LL ans = 0, d = 1;
	for (int i = 1; i <= n; i ++) {
		ans += d;
		d *= b;
	}
	return ans;
}
LL product_mod(LL a, LL b, LL n)
{
	LL tmp = 0;
	while (b) {
		if (b & 1) {
			tmp += a;
			if (tmp >= n) tmp -= n;
		}
		a <<= 1;
		if (a >= n) a -= n;
		b >>= 1;
	}
	return tmp;
}
LL power_mod(LL a, LL m, LL n)
{
	LL ans = 1;
	a %= n;
	while(m) {
		if(m & 1) ans = product_mod(ans, a, n);
		a = product_mod(a, a, n);
		m >>= 1;
	}
	return ans;
}
bool Miller_Rabbin(LL n)//以a为底对n做测试
{
	if(n < 2) return false;
	if(n == 2) return true;
	if((n & 1) == 0) return false;
	srand(time(NULL));
	for(int i = 1; i <= 20; i ++){
		LL a = rand() % (n-2) + 1;
		if(power_mod(a,n-1,n) != 1) {
			return false;
		}
	}
	return true;
}
void work()
{
	if (Miller_Rabbin(getP())) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main()
{
	while (cin >> b >> n) {
		work();
	}
    return 0;
}
