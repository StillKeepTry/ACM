/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月20日 星期六 20时59分21秒
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
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N;

void work()
{
    if (N <= 3) {
        printf("NO\n"); return ;
    }
    printf("YES\n");
    if (N % 4 == 0) {
        int x = 1;
        for (int i = 2; i <= 4; i ++) {
            printf("%d * %d = %d\n", x, i, x * i);
            x = x * i;
        }
        for (int i = 5; i <= N; i ++) {
            if (i % 4 == 1) {
                printf("%d + %d = %d\n", x, i, x + i);
                x += i;
            }
            if (i % 4 == 2) {
                printf("%d - %d = %d\n", x, i, x - i);
                x -= i;
            }
            if (i % 4 == 3) {
                printf("%d - %d = %d\n", x, i, x - i);
                x -= i;
            }
            if (i % 4 == 0) {
                printf("%d + %d = %d\n", x, i, x + i);
                x += i;
            }
        }
        return ;
    }
    if (N % 4 == 1) {
        printf("4 * 5 = 20\n");
        printf("20 + 3 = 23\n");
        printf("23 + 2 = 25\n");
        printf("25 - 1 = 24\n");
        int x = 24;
        for (int i = 6; i <= N; i ++) {
            if (i % 4 == 2) {
                printf("%d + %d = %d\n", x, i, x + i);
                x += i;
            }
            if (i % 4 == 3) {
                printf("%d - %d = %d\n", x, i, x - i);
                x -= i;
            }
            if (i % 4 == 0) {
                printf("%d - %d = %d\n", x, i, x - i);
                x -= i;
            }
            if (i % 4 == 1) {
                printf("%d + %d = %d\n", x, i, x + i);
                x += i;
            }
        }
        return ;
    }
    if (N % 4 == 2) {
        printf("5 * 6 = 30\n");
        printf("30 - 4 = 26\n");
        printf("26 - 3 = 23\n");
        printf("23 - 1 = 22\n");
        printf("22 + 2 = 24\n");
        int x = 24;
        for (int i = 7; i <= N; i ++) {
            if (i % 4 == 3) {
                printf("%d + %d = %d\n", x, i, x + i);
                x += i;
            }
            if (i % 4 == 0) {
                printf("%d - %d = %d\n", x, i, x - i);
                x -= i;
            }
            if (i % 4 == 1) {
                printf("%d - %d = %d\n", x, i, x - i);
                x -= i;
            }
            if (i % 4 == 2) {
                printf("%d + %d = %d\n", x, i, x + i);
                x += i;
            }
        }
        return ;
    }
    if (N % 4 == 3) {
        printf("5 * 7 = 35\n");
        printf("35 - 6 = 29\n");
        printf("29 - 4 = 25\n");
        printf("25 - 1 = 24\n");
        printf("3 - 2 = 1\n");
        printf("24 * 1 = 24\n");
        int x = 24;
        for (int i = 8; i <= N; i ++) {
            if (i % 4 == 0) {
                printf("%d + %d = %d\n", x, i, x + i);
                x += i;
            }
            if (i % 4 == 1) {
                printf("%d - %d = %d\n", x, i, x - i);
                x -= i;
            }
            if (i % 4 == 2) {
                printf("%d - %d = %d\n", x, i, x - i);
                x -= i;
            }
            if (i % 4 == 3) {
                printf("%d + %d = %d\n", x, i, x + i);
                x += i;
            }
        }
        return ;
    }
}
int main()
{
    while (scanf("%d", &N) != EOF) {
        work();
    }
    return 0;
}
