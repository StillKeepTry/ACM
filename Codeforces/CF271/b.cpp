/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月06日 星期一 23时35分47秒
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
#define MAXN 100005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, a[MAXN], Q, q[MAXN], sum[MAXN];

void work()
{
    sum[0] = 0;
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i ++) {
        scanf("%d", &q[i]);
        int pos = lower_bound(sum + 1, sum + 1 + N, q[i]) - sum;
        printf("%d\n", pos);
    }

}
int main()
{
    while (scanf("%d", &N) != EOF) {
        work();
    }
    return 0;
}
