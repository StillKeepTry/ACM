/*************************************************************************
	> File Name: d.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月05日 星期日 21时40分32秒
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
#define MAXN 100005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, Q, a[MAXN], q;

map <int, LL> ans;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void work()
{
    ans.clear();
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
    }
    vector < pair <int, LL> > now, pre;
    for (int i = N; i >= 1; i --) {
        now.pb(mp(a[i], 1));
        for (int j = 0; j < now.size(); j ++) {
            now[j].x = gcd(now[j].x, a[i]);
        }
        sort(now.begin(), now.end());
        pair <int, LL> add;
        pre.clear();
        for (int j = 0; j < now.size(); j ++) {
            if (j == 0) {
                add = now[j];
            } else {
                if (now[j - 1].x == now[j].x) {
                    add.y += now[j].y;
                } else {
                    pre.pb(add);
                    add = now[j];
                }
            }
        }
        pre.pb(add);
        now = pre;
        for (int j = 0; j < now.size(); j ++) {
            ans[now[j].x] += now[j].y;
        }
    }
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i ++) {
        scanf("%d", &q);
        cout << ans[q] << endl;
    }
}
int main()
{
    while (scanf("%d", &N) != EOF) {
        work();
    }
    return 0;
}
