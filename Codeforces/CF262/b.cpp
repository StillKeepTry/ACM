/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月20日 星期三 23时23分55秒
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
LL a, b, c;
vector <LL> ans;

bool check(LL x, int sum) {
    int tmp = 0;
    while (x) {
        tmp += x % 10;
        x /= 10;
    }
    if (tmp == sum) return true;
    return false;
}

LL Pow(LL a, LL n)
{
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

LL calc(int x)
{
    LL ans = b * Pow(x, a) + c;
    return ans;
}

void work()
{
    ans.clear();
    for (int i = 0; i <= 100; i ++) {
        LL x = calc(i);
        if (x > 0 && x < 1000000000) {
            if (check(x, i)) {
                ans.pb(x);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    if (ans.size() > 0) {
        for (int i = 0; i < ans.size(); i ++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
}
int main()
{
    while (cin >> a >> b >> c) {
        work();
    }
    return 0;
}
