#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;
template <typename T> inline void CheckMax(T &a, T b) {if (a < b) a = b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int n, m;
string line;
int a[MAXN][MAXN];  
int row[MAXN][MAXN];
vector <int> vec;
int ans = 0;
void work()
{
    memset(row, 0, sizeof(row));
    for (int i = 1; i <= n; i ++) {
        cin >> line;
        for (int j = 0; j < m; j ++) {
            a[i][j+1] = line[j] - '0';
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i][j]) {
                row[i][j] = row[i][j-1] + 1;
            }
        }
    }
    ans = 0;
    for (int i = 1; i <= m; i ++) {
        vec.clear();
        for (int j = 1; j <= n; j ++) {
            vec.push_back(row[j][i]);
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        for (int j = 0; j < n; j ++) {
            int tmp = vec[j] * (j+1);
            CheckMax(ans, tmp);
        }
    }
    cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        work();
    }
    return 0;
}
