/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月12日 星期日 21时56分50秒
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
#define MOD 1000000007
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
LL a, b, ans;

LL Power(LL a, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

LL calc() {
    return (a * (a + 1)) / 2;
}

void work()
{
    ans = 0;
    LL mul = calc() % MOD;
    for (LL i = 1; i < b; i ++) {
        ans = ans + (a * i) % MOD;
        ans = ans + ((b * i) % MOD * mul) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> a >> b) {
        work();
    }
    return 0;
}
