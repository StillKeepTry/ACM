/*************************************************************************
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年09月07日 星期日 23时30分35秒
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
#define MAXN 1005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, P, a[MAXN];
string s;

void work()
{
    cin >> s;
    for (int i = 0; i < N; i ++) {
        a[i + 1] = s[i] - 'a';
    }
    a[0] = -1;
    for (int i = N; i >= 1; i --) {
        int x = a[i];
        for (int j = x + 1; j < P; j ++) {
            if (i >= 2 && j == a[i-2]) continue;
            if (i >= 1 && j == a[i-1]) continue;
            a[i] = j;
            bool flag = 1;
            for (int k = i + 1; k <= N; k ++) {
                flag = 0;
                for (int q = 0; q < P; q ++) {
                    if (k >= 2 && a[k - 2] == q) continue;
                    if (k >= 1 && a[k - 1] == q) continue;
                    a[k] = q;
                    flag = 1;
                    break;
                }
                if (flag == 0) break;
            }
            if (!flag) continue;
            for (int k = 1; k <= N; k ++) {
                printf("%c", 'a' + a[k]);
            }
            printf("\n");
            return ;
        }
    }
    printf("NO\n");
}
int main()
{
    while (scanf("%d %d", &N, &P) != EOF) {
        work();
    }
    return 0;
}
