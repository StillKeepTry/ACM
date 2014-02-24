/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年02月20日 星期四 23时30分21秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
string str;
int len, p, d, a, b, c;
void work()
{
	len = str.length();
	for (int i = 0; i < len; i ++) {
		if (str[i] == '+') p = i;
		if (str[i] == '=') d = i;
	}
	a = p, b = d - p - 1, c = len - d - 1;
	if (a + b == c-2) {
		a = a + 1;
		c = c - 1;
		for (int i = 1; i <= a; i ++) cout << "|";
		cout << "+";
		for (int i = 1; i <= b; i ++) cout << "|";
		cout << "=";
		for (int i = 1; i <= c; i ++) cout << "|";
		cout << endl;
	} else if (a + b == c + 2) {
		if (a > 1) a = a-1;
		else b = b-1;
		c = c+1;	
		for (int i = 1; i <= a; i ++) cout << "|";
		cout << "+";
		for (int i = 1; i <= b; i ++) cout << "|";
		cout << "=";
		for (int i = 1; i <= c; i ++) cout << "|";
		cout << endl;
	} else if (a + b == c) {
		for (int i = 1; i <= a; i ++) cout << "|";
		cout << "+";
		for (int i = 1; i <= b; i ++) cout << "|";
		cout << "=";
		for (int i = 1; i <= c; i ++) cout << "|";
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> str) {
		work();
	}
    return 0;
}
