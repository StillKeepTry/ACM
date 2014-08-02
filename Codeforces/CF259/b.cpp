/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月02日 星期六 00时10分13秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
#define MAXN 105
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline T Abs(T a) {return a>0?a:-a;}
const int INF = 0x3fffffff;
int n, a[MAXN], b[MAXN], dp[MAXN][1 << 17], pre[MAXN][1 << 17], ans[MAXN][1 << 17];
int prime[MAXN] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
vector <int> rec;

int State(int x)
{
    int state = 0;
    for (int i = 0; i < 17; i ++) {
        if (x % prime[i]) {
            continue;
        }
        state = state + (1 << i);
    }
    return state;
}

void work()
{
    rec.clear();
    memset(pre, 0, sizeof(pre));
    fill(dp[0], dp[0] + (1 << 17), INF);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        fill(dp[i], dp[i] + (1 << 17), INF);
    } 
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= 2 * a[i]; j ++) {
            int x = Abs(j - a[i]);
            int state = State(j);
            for (int k = 0; k < (1 << 17); k ++) {
                if (k & state) continue;
                int nextstate = k | state;
                if (dp[i][nextstate] > dp[i-1][k] + x) {
                    dp[i][nextstate] = dp[i-1][k] + x;  
                    ans[i][nextstate] = j;
                    pre[i][nextstate] = k;
                } 
            }
        }
    }
    int MinState = 0, flag = INF;
    for (int i = 0; i < (1 << 17); i ++) {
        if (dp[n][i] < flag) {
            flag = dp[n][i];
            MinState = i;
        }
    }
    for (int i = n; i >= 1; i --) {
        rec.pb(ans[i][MinState]);
        MinState = pre[i][MinState];
    }
    reverse(rec.begin(), rec.end());
    for (int i = 0; i < n; i ++) {
        printf("%d ", rec[i]);
    }
    printf("\n");
}
int main()
{
    while (scanf("%d", &n) != EOF) {
        work();
    }
    return 0;
}
