/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月01日 星期六 23时24分00秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
template <typename T> inline void CheckMax(T &a, T b) {if(a<b) a=b;}
template <typename T> inline void CheckMin(T &a, T b) {if(a>b) a=b;}
LL a, b, ans;
LL add(LL n, LL p)
{
	return (n-p)*(n-p) + p;	
}
LL add2(LL n, LL p)
{
	LL d = n / p, m = n % p;
	LL ans = 0;
	for (int i = 0; i < m; i ++) {
		ans += (d + 1) * (d + 1);
	}
	for (int i = m; i < p; i ++) {
		ans += d * d;
	}
	return ans;
}
LL sub(int p, int &type)
{
	if ((b / (p+2)) && a >= p+1) {
		type = 2;
		return add2(b, p+2);
	} else if (b / (p+1)) {
		type = 1;
		return add2(b, p+1);
	} else {
		type = 0;
		return add2(b, p);
	}
}
void work()
{
	if (b == 0) {
		cout << a * a << endl;
		for (int i = 1; i <= a; i ++) cout << "o";
		cout << endl;
		return ;
	}
	if (a == 0) {
		cout << -b*b << endl;
		for (int i = 1; i <= b; i ++) cout << "x";
		cout << endl;
		return ;
	}
	int num;
	if (a > b) {
		num = b;
	} else {
		num = a-1;
	}
	int anstype, cnt;
	ans = 0;
	for (int i = 0; i <= num; i ++) {
		LL tmp = add(a, i);
		int type;
		tmp -= sub(i, type);
		if (i == 0) {
			ans = tmp;
			anstype = type;
			cnt = i;
		}
		else if (tmp > ans) {
			ans = tmp;
			anstype = type;
			cnt = i;
		}
	}
	cout << ans << endl;
	vector <int> va, vb, vc;
	va.push_back(a-cnt);
	for (int i = 0; i < cnt; i ++) {
		va.push_back(1);
	}
	int p1 = cnt + anstype;
	for (int i = 0; i < p1; i ++) {
		vb.push_back(b / p1);
	}
	for (int i = 0; i < b % p1; i ++) {
		vb[i] = vb[i] + 1;
	}
	int pb = 0, pa = 0;
	if (anstype == 2) {
		for (int i = 0; i < vb[0]; i ++) cout << "x";
		pb ++;
	}
	for (int i = 0; i < va[0]; i ++) cout << "o";
	for (int i = 0; i < cnt; i ++) {
		for (int j = 0; j < vb[pb]; j ++) cout << "x";
		pb ++;
		for (int j = 0; j < va[i+1]; j ++) cout << "o";
	}
	if (anstype == 2 || anstype == 1) {
		for (int i = 0; i < vb[pb]; i ++) cout << "x";
	}
	cout << endl;
}
int main()
{
	cin >> a >> b;
	work();
    return 0;
}
