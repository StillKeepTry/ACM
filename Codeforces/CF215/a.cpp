#include <bits/stdc++.h>
#define LL long long
#define MAXN 100005
using namespace std;
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if(a<b) a=b;}
template <typename T> inline void CheckMin(T &a, T b) {if(a>b) a=b;}
template <typename T> inline T Abs(T a) {return a>0?a:-a;}
string str;
int m;
int l, r;
int cnt[MAXN];
int num[MAXN][3];
void work()
{
	cin >> m;
	memset(num,0,sizeof(num));
	for (int i = 0; i < str.length(); i ++) {
		num[i+1][0] = num[i][0];
		num[i+1][1] = num[i][1];
		num[i+1][2] = num[i][2];
		if (str[i] == 'x') {
			num[i+1][0] ++;
		}
		if (str[i] == 'y') {
			num[i+1][1] ++;
		}
		if (str[i] == 'z') {
			num[i+1][2] ++;
		}
	}
	for (int i = 0; i < m; i ++) {
		cin >> l >> r;
		int numx, numy, numz;
		numx = num[r][0] - num[l-1][0];
		numy = num[r][1] - num[l-1][1];
		numz = num[r][2] - num[l-1][2];
		int len = r - l + 1;
		if (len < 3) {
			cout << "YES" << endl;
			continue;
		}
		if (len % 3 == 0) {
			int d = len / 3;
			if (numx == d && numy == d && numz == d) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else if (len % 3 == 1) {
			int d = len / 3;
			if ((numx == d+1 && numy == d && numz == d) ||
				(numx == d && numy == d+1 && numz == d) ||
				(numx == d && numy == d && numz == d+1)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else {
			int d = len / 3;
			if ((numx == d+1 && numy == d+1 && numz == d) || 
				(numx == d+1 && numy == d && numz == d+1) ||
				(numx == d && numy == d+1 && numz == d+1)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}
int main()
{
	while (cin >> str) {
		work();
	}
	return 0;
}