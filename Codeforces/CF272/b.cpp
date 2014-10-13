/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月12日 星期日 22时36分09秒
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
typedef pair<LL, LL> PII;
typedef vector<int> vi;
int N, K;

vector < pair <PII, PII> > ans;

void work()
{
    ans.clear();
    LL a = 1, maxLen = 0;
    for (int i = 1; i <= N; i ++) {
        ans.pb(mp(mp(a * K, (a + 1) * K), mp((a + 2) * K, (a + 4) * K)));
        maxLen = (a + 4) * K;
        a += 6;
    }
    cout << maxLen << endl;
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i].x.x << " " << ans[i].x.y << " " << ans[i].y.x << " " << ans[i].y.y << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> N >> K) {
        work();
    }
    return 0;
}
