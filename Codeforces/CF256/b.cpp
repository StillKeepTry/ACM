/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月17日 星期四 21时31分43秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
string s, t;

bool Automation(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.length()) {
        if (s[i] == t[j]) {
            i ++, j ++;
        } else {
            i ++;
        }
    }
    if (j == t.length()) return true;
    return false;
}

bool array(string s, string t)
{
    int a[30] = {}, b[30] = {};
    for (int i = 0; i < s.length(); i ++) {
        a[s[i] - 'a'] ++;
    }
    for (int i = 0; i < t.length(); i ++) {
        b[t[i] - 'a'] ++;
    }
    for (int i = 0; i < 26; i ++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool both(string s, string t)
{
    int a[30] = {}, b[30] = {};
    for (int i = 0; i < s.length(); i ++) {
        a[s[i] - 'a'] ++;
    }
    for (int i = 0; i < t.length(); i ++) {
        b[t[i] - 'a'] ++;
    }
    for (int i = 0; i < 26; i ++) {
        if (a[i] < b[i]) return false;
    }
    return true;
}

void work()
{
    cin >> t;
    if (Automation(s, t)) {
        printf("automaton\n");
    } else if (array(s, t)) {
        printf("array\n");
    } else if (both(s, t)) {
        printf("both\n");
    } else {
        printf("need tree\n");
    }
}
int main()
{
    while (cin >> s) {
        work();
    }
    return 0;
}
