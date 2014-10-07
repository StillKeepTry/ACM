/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年10月05日 星期日 21时09分59秒
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
#define MAXN 25
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int N, M, dir1[MAXN], dir2[MAXN];
string a, b;
bool vis[MAXN][MAXN];

bool bfs(int x, int y) {
    memset(vis, 0, sizeof(vis));
    queue <PII> Q;
    Q.push(mp(x, y));
    vis[x][y] = true;
    while (!Q.empty()) {
        PII now = Q.front();
        Q.pop();
        PII next;
        if (dir1[now.x]) {
            next = now;
            next.y --;
        } else {
            next = now;
            next.y ++;
        }
        if (next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= M) {
            if (!vis[next.x][next.y]) {
                vis[next.x][next.y] = true;
                Q.push(next);
            }
        }
        if (dir2[now.y]) {
            next = now;
            next.x ++;
        } else {
            next = now;
            next.x --;
        }
        if (next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= M) {
            if (!vis[next.x][next.y]) {
                vis[next.x][next.y] = true;
                Q.push(next);
            }
        }
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            if (!vis[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void work()
{
    cin >> a;
    for (int i = 0; i < N; i ++) {
        dir1[i + 1] = a[i] == '<' ? 1 : 0;
    }
    cin >> b;
    for (int i = 0; i < M; i ++) {
        dir2[i + 1] = b[i] == 'v' ? 1 : 0;
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            if (!bfs(i, j)) {
                printf("NO\n"); return ;
            }
        }
    }
    printf("YES\n"); return ;
}
int main()
{
    while (scanf("%d %d", &N, &M) != EOF) {
        work();
    }
    return 0;
}
