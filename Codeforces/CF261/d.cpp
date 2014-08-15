/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月15日 星期五 22时56分26秒
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
#define MAXN 1000005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n;
map <LL, int> Ma, Mb;
LL a[MAXN], a1[MAXN], a2[MAXN], ans;
LL c[MAXN];

int lowbits(int x)
{
    return x & (-x);
}

void add(int pos)
{
    while (pos <= n) {
        c[pos] += 1;
        pos += lowbits(pos);
    }
}

LL query(int ask)
{
    LL sum = 0;
    while (ask) {
        sum += c[ask];
        ask -= lowbits(ask);
    }
    return sum;
}

void work()
{
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    Ma.clear(), Mb.clear();
    for (int i = 1; i <= n; i ++) {
        if (Ma.find(a[i]) == Ma.end()) {
            a1[i] = 1;
            Ma.insert(mp(a[i], 1));
        } else {
            a1[i] = Ma[a[i]] + 1;
            Ma[a[i]] ++;
        }
    }
    for (int i = n; i >= 1; i --) {
        if (Mb.find(a[i]) == Mb.end()) {
            a2[i] = 1;
            Mb.insert(mp(a[i], 1));
        } else {
            a2[i] = Mb[a[i]] + 1;
            Mb[a[i]] ++;
        }
    }
    ans = 0;
    memset(c, 0, sizeof(c));
    for (int i = n; i >= 1; i --) {
        ans += query(a1[i] - 1);   
        add(a2[i]);
    }
    cout << ans << endl;
}
int main()
{
    while (scanf("%d", &n) != EOF) {
        work();
    }
    return 0;
}
