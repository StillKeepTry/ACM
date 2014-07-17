/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月17日 星期四 21时30分34秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN
#define LL long long 
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int a, b, c, a1, a2, a3, b1, b2, b3, n;
void work()
{
    cin >> b1 >> b2 >> b3;
    cin >> n;
    a = a1 + a2 + a3;
    b = b1 + b2 + b3;
    if (a % 5) {
        a = a / 5 + 1;
    } else {
        a = a / 5;
    }
    if (b % 10) {
        b = b / 10 + 1;
    } else {
        b = b / 10;
    }
    if (a + b <= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main()
{
    while (cin >> a1 >> a2 >> a3) {
        work();
    }
    return 0;
}
