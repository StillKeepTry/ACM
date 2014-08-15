/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月15日 星期五 22时56分16秒
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
#define MAXN 200005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
LL n; 
LL b[MAXN];

void work()
{
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    sort(b + 1, b + 1 + n);
    LL d = b[n] - b[1];
    LL n1, n2;
    n1 = n2 = 0;
    for (int i = 1; i <= n; i ++) {
        if (b[i] == b[1]) n1 ++;
        else break;
    }
    for (int i = n; i >= 1; i --) {
        if (b[i] == b[n]) {
            n2 ++;
        } else {
            break;
        }
    }
    if (b[1] == b[n]) {
        cout << d << " " << n * (n - 1) / 2 << endl;
    } else {
        cout << d << " " << n1 * n2 << endl;
    }
}
int main()
{
    while (cin >> n) {
        work();
    }
    return 0;
}
