/*************************************************************************
	> File Name: Manacher.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月01日 星期三 18时44分54秒
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
char s[MAXN];
int len[MAXN];

void Manacher(char s[], int len[], int n) {
    memset(len, 0, sizeof(len));
    for (int i = 0, j = 0, k; i < 2 * n; i += k, j = Max(j - k, 0)) {
        while (i - j >= 0 && i + j + 1 < 2 * n && s[(i - j) / 2] == s[(i + j + 1) / 2]) j ++;
        len[i] = j;
        for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] < j - k; k ++) {
            len[i + k] = Min(len[i - k], j - k);
        }
    }
}
