/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月15日 星期五 22时56分10秒
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
template <typename T> inline T Abs(T a) {return a>0?a:-a;}
int a1, b1, a2, b2;

void work()
{
    if (a1 == a2 && b2 == b1) {
        printf("-1\n"); return ;
    }
    if (a1 == a2) {
        int x = Abs(b2 - b1);
        printf("%d %d %d %d\n", a1 + x, b1, a1 + x, b2); return ;
    }
    if (b1 == b2) {
        int x = Abs(a2 - a1);
        printf("%d %d %d %d\n", a1, b1 + x, a2, b2 + x); return ;
    }
    if (Abs(b2 - b1) == Abs(a1 - a2)) {
        printf("%d %d %d %d\n", a1, b2, a2, b1); return ;
    }
    printf("-1\n");
}
int main()
{
    while (scanf("%d %d %d %d", &a1, &b1, &a2, &b2) != EOF) {
        work();
    }
    return 0;
}
