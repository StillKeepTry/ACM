/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月05日 星期日 20时59分46秒
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
int K;
int seat[10][20];

void work()
{
    printf("+------------------------+\n");
    memset(seat, 0, sizeof(seat));
    for (int i = 1; i <= 11; i ++) {
        for (int j = 1; j <= 4; j ++) {
            if (K == 0) break;
            if (j == 3) {
                if (i == 1) {
                    seat[j][i] = 1;
                    K --;
                }
            } else {
                seat[j][i] = 1;
                K --;
            }
        }
    }
    for (int i = 1; i <= 4; i ++) {
        printf("|");
        for (int j = 1; j <= 11; j ++) {
            if (seat[i][j]) {
                printf("O.");
            } else {
                if (i == 3 && j != 1) {
                    printf("..");
                } else {
                    printf("#.");
                }
            }
        }
        if (i == 1) {
            printf("|D|)\n");
        } else if (i == 2) {
            printf("|.|\n");
        } else if (i == 3) {
            printf("..|\n");
        } else {
            printf("|.|)\n");
        }
    }
    printf("+------------------------+\n");
}
int main()
{
    while (scanf("%d", &K) != EOF) {
        work();
    }
    return 0;
}
