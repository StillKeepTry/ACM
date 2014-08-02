/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月01日 星期五 23时26分56秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int m, n;
double ans;

double Pow(double m, int n)
{
    double ans = 1.0;
    while (n) {
        if (n & 1) ans = ans * m;
        m = m * m;
        n >>= 1;
    }
    return ans;
}

void work()
{
    ans = m;   
    for (int i = 1; i < m; i ++) {
        ans = ans - Pow(i * 1.0 / (double)m, n);
    }
    printf("%.10lf\n", ans);
}
int main()
{
    while (scanf("%d %d", &m, &n) != EOF) {
        work();
    }
    return 0;
}
