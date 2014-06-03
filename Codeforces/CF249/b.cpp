/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年05月30日 星期五 23时56分05秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 20
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
string a;
int len, k, num[MAXN], now, re[MAXN];
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void work()
{
    memset(num, 0, sizeof(num));
    len = a.length();
    for (int i = 0; i < len; i ++) {
        num[i+1] = a[i] - '0';
    }
    now = 1;
    while (now <= len) {
        fill(re, re+MAXN, 1000);
        int cnt = 0;
        for (int i = 0; i + now <= len; i ++) {
            re[num[i + now]] = Min(cnt, re[num[i + now]]);
            cnt ++;
        }
        for (int i = 9; i >= 0; i --) {
            if (i > num[now] && re[i] <= k) {
                k -= re[i];
                for (int j = re[i]; j > 0; j --) {
                    Swap(num[j+now], num[j+now-1]);
                }
                break;
            }
        }
        now ++;
    }
    for (int i = 1; i <= len; i ++) cout << num[i];
    cout << endl;
}
int main()
{
    while (cin >> a >> k) {
        work();
    }
	return 0;
}
