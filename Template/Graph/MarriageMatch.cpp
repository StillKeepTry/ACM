/*************************************************************************
	> File Name: MarriageMatch.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月03日 星期日 11时24分59秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
#define MAXN 505
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n;

struct People {
    bool single;
    int ask, top, cnt, match, lover[MAXN], need[MAXN], priority[MAXN];
} boy[MAXN], girl[MAXN];

void init()
{
    memset(boy, 0, sizeof(boy));
    memset(girl, 0, sizeof(girl));
}

void stableMatching()
{
    int num = 0;
    while (num < n) {
        num = 0;
        for (int i = 1; i <= n; i ++) {
            if (!boy[i].single) {
                ++ boy[i].ask;
                int u = boy[i].lover[boy[i].ask];
                girl[u].need[++ girl[u].cnt] = i;
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (; girl[i].top < girl[i].cnt;) {
                ++ girl[i].top;
                int u = girl[i].need[girl[i].top];
                if (girl[i].priority[girl[i].ask] < girl[i].priority[u]) {
                    boy[girl[i].ask].single = false;
                    boy[u].single = true;
                    girl[i].ask = u; boy[u].match = i; girl[i].match = u;
                }
            }
            if (girl[i].ask) num ++;
        }
    }
}
