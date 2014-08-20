/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月21日 星期四 00时29分00秒
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
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
LL l, r, k, a[10];

LL check(int num, int state)
{
    LL sum = 0;
    for (int i = 0; i < num; i ++) {
        if (state & (1 << i)) {
            sum = sum ^ a[i];
        }
    }
    return sum;
}

int bit(LL x)
{
    int sum = 0;
    while (x) {
        sum ++;
        x >>= 1;
    }
    return sum;
}

void gao()
{
    for (LL i = l; i <= r; i ++) {
        if (i & 1) continue;
        cout << (i ^ (i + 1)) << endl;
        cout << 2 << endl;
        cout << i << " " << (i + 1) << endl;
        return ;
    } 
}

void work()
{
    if (r - l >= 6) {
        if (k == 1) {
            cout << l << endl;
            cout << 1 << endl;
            cout << l << endl;
            return ;
        }
        if (k == 2) {
            gao(); return ;
        }
        if (k == 3) {
            if (bit(l) == bit(r)) {
                gao(); return ;
            }
            int b = bit(l);
            LL ll = (1ll << b) + (1ll << (b-1));
            LL lll = l ^ ll;
            if (ll <= r && lll <= r && lll >= l) {
                cout << 0 << endl;
                cout << 3 << endl;
                cout << l << " " << ll << " " << lll << endl;return ;
            } else {
                gao(); return ;
            }
        } 
        cout << 0 << endl;
        cout << 4 << endl;
        LL pos;
        for (LL i = l; i <= r; i ++) {
            if (i % 4 == 0) {
                pos = i;
                break;
            }
        }
        for (int i = 0; i < 4; i ++) {
            cout << (pos + i) << " ";
        }
        cout << endl;
    } else {
        int cnt = 0;
        for (LL i = l; i <= r; i ++) {
            a[cnt ++] = i;
        }
        int num = r - l + 1;
        LL Mi = 1e18, ans;
        for (int i = 1; i < (1 << num); i ++) {
            int c = 0;
            for (int j = 0; j < num; j ++) {
                if (i & (1 << j)) c ++;
            }
            if (c > k) continue;
            if (Mi > check(num, i)) {
                Mi = check(num, i);
                ans = i;
            }
        }
        cout << Mi << endl;
        vector <LL> v;
        v.clear();
        for (int i = 0; i < num; i ++) {
            if (ans & (1 << i)) {
                v.pb(a[i]);
            }
        }
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i ++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> l >> r >> k) {
        work();
    }
    return 0;
}
