/*************************************************************************
	> File Name: ThreeSepare.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月22日 星期二 15时13分36秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define eps 1e-9
#define MAXN
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}

double cal(double index)
{
    // 函数值
}

double gao()
{
    // init l and r, 初始化l和r
    double l, r;
    while (fabs(r - l) >= eps) {
        double ll = l + (r - l) / 3;
        double rr = r - (r - l) / 3;
        double s1 = cal(ll);
        double s2 = cal(rr);
        if (s1 >= s2) {
            l = ll;
        } else {
            r = rr;
        }
    }
    return cal(l);
}
