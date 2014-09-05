/*************************************************************************
	> File Name: KMP.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月04日 星期四 19时58分18秒
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

void Next(char s[], int next[]) {
    int i = 0, j = -1, len= strlen(s);
    next[0] = -1;
    while (i < len) {
        if (j == -1 || s[i] == s[j]) {
            i ++; j ++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void KMP(char s[], char p[], int next[]) {
    int i = 0, j = 0, len = strlen(s), len1 = strlen(p);
    while (i < len && j < len1) {
        if (j == -1 || s[i] == p[j]) {
            i ++; j ++;
        } else {
            j = next[j];
        }
    }
}

void work()
{

}
int main()
{
    return 0;
}
