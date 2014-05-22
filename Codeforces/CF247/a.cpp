/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月21日 星期三 23时16分03秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int a1, a2, a3, a4, ans;
string s;
void work()
{
    cin >> s;
    ans = 0;
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == '1') ans += a1;
        if (s[i] == '2') ans += a2;
        if (s[i] == '3') ans += a3;
        if (s[i] == '4') ans += a4;
    }
    cout << ans << endl;
}
int main()
{
    while (cin >> a1 >> a2 >> a3 >> a4) {
        work();
    }
	return 0;
}
