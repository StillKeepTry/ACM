/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月20日 星期三 23时23分46秒
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
int n, m;

void work()
{
    int cnt = 0;
    while (1) {
        cnt ++;
        if (n == 0) {
            printf("%d\n", cnt - 1);
            return ;
        }
        n --;
        if (cnt % m == 0) {
            n ++;
        }
    }
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF) {
        work();
    }
    return 0;
}
