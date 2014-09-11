/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月26日 星期二 22时00分28秒
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
#define MAXN 300005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int N, a[MAXN];
LL ans;

void work()
{
    ans = 0;
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + N);
    for (int i = N; i >= 1; i --) {
        ans += (LL)a[i] * (LL)i;
    }
    for (int i = 1; i < N; i ++) {
        ans += (LL)a[i];
    }
    cout << ans << endl;
}
int main()
{
    while (scanf("%d", &N) != EOF) {
        work();
    }
    return 0;
}
