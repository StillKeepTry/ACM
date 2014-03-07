/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月06日 星期四 00时08分15秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define X first
#define Y second
template <typename T> inline void Swap(T &a, T &b) {T t = b; b = a; a = t;}
LL n, m, x, y, z, p, a, b;
typedef pair <LL, LL> PII;
void rotate1(PII &pii)
{
	LL x = pii.Y;
	LL y = n + 1 - pii.X;
	pii.X = x, pii.Y = y;
}
void rotate2(PII &pii)
{
	pii.Y = m - pii.Y + 1;
}
void rotate3(PII &pii)
{
	LL x = m + 1 - pii.Y;
	LL y = pii.X;
	pii.X = x, pii.Y = y;
}
void print(PII pii)
{
	if (x > 0) {
		for (int i = 1; i <= x; i ++) {
			rotate1(pii);
			Swap(n, m);
		}
	}
	if (y > 0) {
		for (int i = 1; i <= y; i ++) {
			rotate2(pii);
		}
	}
	if (z > 0) {
		for (int i = 1; i <= z; i ++) {
			rotate3(pii);
			Swap(n, m);
		}
	}
	cout << pii.X << " " << pii.Y << endl;
}
void work()
{
	x %= 4, y %= 2, z %= 4;
	static vector<PII> v;
	v.clear();
	for (int i = 1; i <= p; i ++) {
		cin >> a >> b;	
		PII node = PII(a, b);
		v.push_back(node);
	}
	LL nn = n, mm = m;
	for (int i = 0; i < p; i ++) {
		n = nn, m = mm;
		print(v[i]);	
	}
}
int main()
{
	while (cin >> n >> m >> x >> y >> z >> p) {
		work();
	}
    return 0;
}
