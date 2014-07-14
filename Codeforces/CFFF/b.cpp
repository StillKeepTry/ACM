/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月13日 星期日 20时57分03秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 30
string s;
int k, w[MAXN], ans;
void work()
{
    cin >> k;
    ans = 0;
    for (int i = 1; i <= 26; i ++) {
        cin >> w[i];
    }
    for (int i = 0; i < s.length(); i ++) {
        ans = ans + (i + 1) * w[s[i] - 'a' + 1];
    }
    sort(w+1, w+27);
    int x = s.length();
    for (int i = 1; i <= k; i ++) {
        ans = ans + (x + i) * w[26];
    }
    printf("%d\n", ans);
}
int main()
{
    while (cin >> s) {
        work();
    }
    return 0;
}
