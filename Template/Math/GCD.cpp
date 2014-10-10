/*************************************************************************
	> File Name: GCD.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月08日 星期三 19时57分23秒
 ************************************************************************/

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define eps 1e-8
#define x first
#define y second
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a * b / gcd(a, b);
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, x, y), t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

LL muline(LL b, LL n) {
    LL x, y;
    if (exgcd(b, n, x, y) != 1) {
        return -1;
    }
    return (x % n + n) % n;
}

LL chinar(LL a1, LL m1, LL a2, LL m2) {
    LL b1 = a2 % m2 - a1 % m1, k1, k2;
    LL d = gcd(m1, m2);
    if (b1 % d) {
        return -1;
    }
    m1 /= d, m2 /= d, b1 /= d;
    exgcd(m1, m2, k1, k2);
    k1 = ((k1 * b1) % m2 + m2) % m2;
    return k1 * m1 * d + a1 % (m1 * d);
}

LL china(LL a[], LL m[], int n) {
    for (int i = 2; i <= n; i ++) {
        a[i] = chinar(a[i - 1], m[i - 1], a[i], m[i]);
        if (a[i] == -1) return -1;
        m[i] = lcm(m[i], m[i - 1]);
    }
    return a[n];
}

void work()
{

}
int main()
{
    return 0;
}
