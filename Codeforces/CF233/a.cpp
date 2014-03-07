/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月01日 星期六 23时17分48秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
template <typename T> inline T Min(T a, T b) {return a>b?b:a;}
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline void CheckMin(T &a, T b) {if(a>b) a=b;}
template <typename T> inline void CheckMax(T &a, T b) {if(a<b) a=b;}
int n, p, k;
void work()
{
	int mi = p-k, ma = p+k;
	if (mi > 1) {
		cout << "<< ";
		for (int i = mi; i < p; i ++) cout << i << " ";
	} else {
		for (int i = 1; i < p; i ++) cout << i << " ";
	}
	cout << "(" << p << ") ";
	if (ma < n) {
		for (int i = p+1; i <= ma; i ++) cout << i << " ";
		cout << ">> ";
	} else {
		for (int i = p+1; i <= n; i ++) cout << i << " ";
	}
	cout << endl;
}
int main()
{
	while (cin >> n >> p >> k) {
		work();
	}
    return 0;
}
