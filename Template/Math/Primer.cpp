/*************************************************************************
	> File Name: Primer.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年09月05日 星期五 14时47分29秒
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

#define N 1000005
int prim[N], p[N] = {}, pn;
void Init_Prime(int n) {
    pn = 0;
    p[0] = p[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (p[i]) {
            continue;
        }
        for (int j = i; j <= n; j += i) {
            p[j] = i;
        }
        prim[pn ++] = i;
    }
}

// small number eular val, O(sqrt(n))
int eular(int x) {
    if (x == 1) return 1;
    int ans = x;
    for (int i = 2; i * i <= x; i ++) {
        if (x % i) continue;
        while (x % i == 0) x /= i;
        ans = ans / i * (i - 1);
    }
    if (x != 1) {
        ans = ans / x * (x - 1);
    }
    return ans;
}

// Big Number eular val, O(log(n)), need prime table
LL Eular(LL x) {
    if (x == 1) return 1;
    LL ans = x;
    for (int i = 0; p[i] * p[i] <= x; i ++) {
        if (x % p[i]) continue;
        while (x % p[i] == 0) x /= p[i];
        ans = ans / p[i] * (p[i] - 1);
    }
    if (x != 1) {
        ans = ans / x * (x - 1);
    }
    return ans;
}

int phi[N];
void InitPhi() {
    phi[0] = phi[1] = 1;
    for (int i = 0; i < pn; i ++) {
        phi[p[i]] = p[i] - 1;
    }
    for (int i = 2; i <= N; i ++) {
        for (int j = 0; j < pn && p[j] * i <= N; j ++) {
            if (i % p[j]) {
                phi[i * p[j]] = phi[i] * (p[j] - 1);
            } else {
                phi[i * p[j]] = phi[i] * p[j];
            }
        }
    }
} 

void find_factor(int p[], int n) {
    int temp;
    for (int i = 0; i < pn && prim[i] <= n; i ++) {
        temp = n;
        while (temp) {
            p[i] += temp / prim[i];
            temp /= prim[i];
        }
    }
}


