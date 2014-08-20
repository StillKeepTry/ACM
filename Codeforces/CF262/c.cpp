/*************************************************************************
	> File Name: c.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月20日 星期三 23时24分57秒
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
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
#define MAXN 100005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int w, n, m;
LL a[MAXN], add[MAXN];


bool check(LL x)
{
    memset(add, 0, sizeof(add));
    LL cnt = 0;
    for (int i = 1; i <= n; i ++) {
        add[i] += add[i-1];
        if (a[i] + add[i] < x) {
            LL l = i, r = Min(i + w, n + 1);
            LL dis = x - add[i] - a[i];
            add[l] += dis;
            add[r] -= dis;
            cnt += dis;
        }
    }
    if (cnt <= m) return true;
    return false;
}

LL gao()
{
    LL l = 1, r = 1e10;
    while (r - l > 1) {
        LL mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        } 
    }
    if (check(r)) return r;
    if (check(l)) return l;
}

void work()
{
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    cout << gao() << endl;
}
int main()
{
    while (scanf("%d %d %d", &n, &m, &w) != EOF) {
        work();
    }
    return 0;
}
