/*************************************************************************
	> File Name: b.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月01日 星期日 21时07分53秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 25
typedef vector<int> vi;
map<int, int> ma;
int sum, limit, need[MAXN];
vi a[MAXN], ans;
int lowbits(int x)
{
    return x & (-x);
}
void work()
{
    for (int i = 0; i <= 20; i ++) {
        ma[(1<<i)] = i+1;
        a[i].clear();
    }
    for (int i = 1; i <= limit; i ++) {
        int val = lowbits(i);
        val = ma[val];
        a[val].push_back(i);
    }
    ans.clear();
    memset(need, 0, sizeof(need));
    for (int i = 0; i <= 20; i ++) {
        if (sum & (1<<i)) {
            need[i+1] = 1;
        }
    }
    for (int i = 21; i >= 1; i --) {
        if (need[i]) {
            for (int j = 0; j < a[i].size(); j ++) {
                ans.push_back(a[i][j]);
                need[i] --;
                if (need[i] == 0) break;
            }
            if (need[i]) {
                need[i-1] += need[i] * 2;
            }
        }
    }
    if (need[0]) {
        cout << "-1" << endl;
    } else {
        cout << ans.size() << endl;
        for (int j = 0; j < ans.size(); j ++) {
            cout << ans[j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    while (cin >> sum >> limit) {
        work();
    }
	return 0;
}
