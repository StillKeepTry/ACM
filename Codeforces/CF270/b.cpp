/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月28日 星期日 23时38分39秒
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
#define MAXN 2005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, K, f[MAXN], ans;

void work()
{
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &f[i]);
    }
    sort(f + 1, f + 1 + N);
    reverse(f + 1, f + 1 + N);
    ans = 0;
    for (int i = 1; i <= N; i += K) {
        ans += (f[i] - 1) * 2;
    }
    printf("%d\n", ans);
}
int main()
{
    while (scanf("%d %d", &N, &K) != EOF) {
        work();
    }
    return 0;
}
