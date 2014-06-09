/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月08日 星期日 23时16分38秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 55
int n, v, s[MAXN][MAXN], k[MAXN];
vector <int> ans;
void work()
{
    ans.clear();
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j ++) {
            scanf("%d", &s[i][j]);
        }
        sort(s[i] + 1, s[i] + 1 + k[i]);
        if (s[i][1] < v) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    while (scanf("%d %d", &n, &v) != EOF) {
        work();
    }
	return 0;
}
