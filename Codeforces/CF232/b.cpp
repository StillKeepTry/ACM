/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月26日 星期三 23时23分28秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline void CheckMin(T &a, T b) {if(a>b) a=b;}
template <typename T> inline void CheckMax(T &a, T b) {if(a<b) a=b;}
typedef pair <int, int> PII;
int t;
LL n, l, r;
void work()
{
	for (int i = 1; i <= t; i ++) {
		cin >> n >> l >> r;
		if (n < l) {
			cout << "No" << endl;
			continue;
		}
		LL div = n % l;
		LL cnt = n / l;
		LL len = div / cnt;
		if (div % cnt) len ++;
		if (len > (r-l)) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}
int main()
{
	while (cin >> t) {
		work();
	}
    return 0;
}
