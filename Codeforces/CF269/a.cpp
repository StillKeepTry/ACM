/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月26日 星期五 23时20分27秒
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
#define MAXN 10
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int l[MAXN], num[MAXN];

void work()
{
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= 6; i ++) {
        num[l[i]] ++;
    }
    int flag = 0;
    for (int i = 1; i <= 9; i ++) {
        if (num[i] >= 4) {
            num[i] -= 4;
            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("Alien\n"); return ;
    } else {
        for (int i = 1; i <= 9; i ++) {
            if (num[i] == 2) {
                printf("Elephant\n"); return ;
            }
        }
        printf("Bear\n"); return ;
    }

}
int main()
{
    while (scanf("%d %d %d %d %d %d", &l[1], &l[2], &l[3], &l[4], &l[5], &l[6]) != EOF) {
        work();
    }
    return 0;
}
