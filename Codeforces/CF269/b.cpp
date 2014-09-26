/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月26日 星期五 23时20分36秒
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
int N, a[MAXN];

vector <PII> vec;

vi num[MAXN];

void work()
{
    for (int i = 1; i <= 2000; i ++) {
        num[i].clear();
    }
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
        num[a[i]].pb(i);
    }
    int flag = 0, f2 = 0;
    for (int i = 1; i <= 2000; i ++) {
        if (num[i].size() == 2) {
            f2 ++;
        } else if (num[i].size() > 2) {
            flag = 1;
        }
    }
    if (flag) {
        printf("YES\n");
    } else {
        if (f2 > 1) {
            printf("YES\n");
        } else {
            printf("NO\n"); return ;
        }
    }
    if (flag) {
        for (int i = 0; i < 3; i ++) {
            for (int j = 1; j <= 2000; j ++) {
                for (int k = 0; k < num[j].size(); k ++) {
                    int p = (k + i) % num[j].size();
                    printf("%d ", num[j][p]);
                }
            }
            printf("\n");
        }
    } else {
        for (int j = 1; j <= 2000; j ++) {
            for (int k = 0; k < num[j].size(); k ++) {
                printf("%d ", num[j][k]);
            }
        }
        printf("\n");
        int flag = 0;
        for (int i = 1; i <= 2000; i ++) {
            if (!flag && num[i].size() == 2) {
                reverse(num[i].begin(), num[i].end());
                flag = 1;
            }
            for (int k = 0; k < num[i].size(); k ++) {
                printf("%d ", num[i][k]);
            }
        }
        printf("\n");
        flag = 0;
        for (int i = 1; i <= 2000; i ++) {
            if (num[i].size() == 2) {
                if (flag < 2) {
                    flag ++;
                }
                if (flag == 2) {
                    reverse(num[i].begin(), num[i].end());
                }
            }
            for (int k = 0; k < num[i].size(); k ++) {
                printf("%d ", num[i][k]);
            }
        }
        printf("\n");
    }
}
int main()
{
    while (scanf("%d", &N) != EOF) {
        work();
    }
    return 0;
}
