#include <bits/stdc++.h>
using namespace std;
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
string a;
int num[10];
bool check() 
{
	for (int i = 1; i <= 9; i ++) {
		if (num[i]) return true;
	}
	return false;
}
void work() 
{
	int len = a.length();
	memset(num, 0, sizeof(num));
	for (int i = 0; i < len; i ++) {
		num[a[i] - '0'] ++;
	}
	num[1] --;
	num[6] --;
	num[8] --;
	num[9] --;
	if (check()) {
		int mod = 0;
		for (int i = 9; i >= 0; i --) {
			while (num[i] --) {
				cout << i;
				mod = (mod * 10 + i) % 7;
			}
		}
		mod = mod * 10000 % 7;
		if (mod == 0) cout << 1869;
		if (mod == 1) cout << 1896;
		if (mod == 2) cout << 1986;
		if (mod == 3) cout << 1698;
		if (mod == 4) cout << 6891;
		if (mod == 5) cout << 9816;
		if (mod == 6) cout << 8961;
	} else {
		cout << 1869;
		for (int i = 0; i < num[0]; i ++) {
			cout << 0;
		}
	}
	cout << endl;
}
int main()
{
	while (cin >> a) {
		work();
	}
	return 0;
}
