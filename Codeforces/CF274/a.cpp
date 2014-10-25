/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月25日 星期六 00时45分26秒
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
int N, K;

int a[MAXN], top, rail;

void work()
{
    a[1] = 1;
    top = 2, rail = N;
    bool flag = 0;
    for (int i = 1; i < K; i ++) {
        a[i + 1] = (i & 1) == 1 ? rail : top; 
        if (i & 1) {
            rail --;
            flag = 1;
        } else {
            top ++;
            flag = 0;
        }
    }
    if (flag) {
        for (int i = K + 1; i <= N; i ++) {
            a[i] = a[i - 1] - 1;
        }
    } else {
        for (int i = K + 1; i <= N; i ++) {
            a[i] = a[i - 1] + 1;
        }
    }
    for (int i = 1; i <= N; i ++) {
        printf("%d%c", a[i], " \n"[i == N]);
    }
}
int main()
{
    while (scanf("%d %d", &N, &K) != EOF) {
        work();
    }
    return 0;
}
