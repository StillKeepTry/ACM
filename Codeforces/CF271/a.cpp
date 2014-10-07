/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月06日 星期一 23时29分43秒
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
#define MAXN 105
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
char op[2], s[MAXN];

char entry[3][MAXN] = {
    "qwertyuiop",
    "asdfghjkl;",
    "zxcvbnm,./"
};

void work()
{
    scanf("%s", s);
    int d;
    if (op[0] == 'R') {
        d = -1;
    } else {
        d = 1;
    }
    for (int i = 0; i < strlen(s); i ++) {
        for (int j = 0; j < 3; j ++) {
            for (int k = 0; k < 10; k ++) {
                if (entry[j][k] == s[i]) {
                    printf("%c", entry[j][k + d]);
                }
            }
        }
    }
    printf("\n");
}
int main()
{
    while (scanf("%s", op) != EOF) {
        work();
    }
    return 0;
}
