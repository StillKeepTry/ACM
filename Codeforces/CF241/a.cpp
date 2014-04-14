/*************************************************************************
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014å¹´04æ13æ¥ æææ¥ 15æ¶53å16ç§
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n;
LL x, l, r;
string op, y;
void work()
{
    l = -2 * 1e9, r = 2 * 1e9;
    for (int i = 1; i <= n; i ++) {
        cin >> op >> x >> y;
        if (y == "Y") {
            if (op == ">=") {
                l = Max(l, x);
            }
            if (op == "<") {
                r = Min(r, x-1);
            }
            if (op == "<=") {
                r = Min(r, x);
            }
            if (op == ">") {
                l = Max(l, x+1);
            }
        } else {
            if (op == ">=") {
                r = Min(r, x-1);
            }
            if (op == "<") {
                l = Max(l, x);
            }
            if (op == "<=") {
                l = Max(l, x+1);
            }
            if (op == ">") {
                r = Min(r, x);
            }
        }
    }
    if (l > r) {
        cout << "Impossible" << endl;
    } else {
        cout << l << endl;
    }
}
int main()
{
    while (cin >> n) {
        work();
    }
    return 0;
}
