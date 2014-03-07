/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: a.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月26日 星期日 11时57分39秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define X first
#define Y second
#define PB push_back
#define eps 1e-9
template<typename T> inline void CheckMax(T &a, T b) {if(a<b) a=b;}
template<typename T> inline void CheckMin(T &a, T b) {if(a>b) a=b;}
template<typename T> inline T Max(T a, T b) {return a>b?a:b;}
template<typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int,int> PII;
PII tri[3]; 
LL Sum, a, b, c;
double ans;
LL getarea()
{
	return Sum * (Sum - 2*a) * (Sum - 2*b) * (Sum - 2*c);
}
LL area(vector<int> vec)
{
	for (int i = 1; i < vec.size(); i ++) {
		vec[i] = vec[i-1] + vec[i];
	}
	LL ans = 0;
	for (int i = 0; i < 4; i ++) {
		for (int j = i+1; j < 5; j ++) {
			a = vec[i], b = vec[j] - vec[i], c = vec[5] - vec[j];
			if (a + b <= c || b + c <= a || a + c <= b) continue;
		   	ans = Max(ans , getarea());
		}
	}	
	for (int i = 0; i < 3; i ++) {
		for (int j = i+1; j < 4; j ++) {
			for (int k = j+1; k < 5; k ++) {
				int a1 = vec[i], a2 = vec[j] - vec[i], a3 = vec[k] - vec[j], a4 = vec[5] - vec[k];
				a = a1 + a4, b = a2, c = a3;
				if (a + b <= c || b + c <= a || a + c <= b) continue;
				ans = Max(ans, getarea());
			}
		}
	}
	return ans;
}
void work()
{
	cin >> tri[1].X >> tri[1].Y;
	cin >> tri[2].X >> tri[2].Y;
	Sum = 0;
	for (int i = 0; i < 3; i ++) {
		Sum += (tri[i].X + tri[i].Y);
	}
	LL cnt = 0;
	for (int i = 0; i < 3; i ++) {
		vector<int> vec;
		for (int i1 = 0; i1 < 2; i1 ++) {
			for (int j = 0; j < 3; j ++) {
				if (j == i) continue;
				for (int j1 = 0; j1 < 2; j1 ++) {
					for (int k = 0; k < 3; k ++) {
						if (k == i || k == j) continue;
						for (int k1 = 0; k1 < 2; k1 ++) {
							vector <int> vec;
							if (i1 & 1) vec.PB(tri[i].X), vec.PB(tri[i].Y);
							else vec.PB(tri[i].Y), vec.PB(tri[i].X);
							if (j1 & 1) vec.PB(tri[j].X), vec.PB(tri[j].Y);
							else vec.PB(tri[j].Y), vec.PB(tri[j].X);
							if (k1 & 1) vec.PB(tri[k].X), vec.PB(tri[k].Y);
							else vec.PB(tri[k].Y), vec.PB(tri[k].X);
							cnt = Max(cnt, area(vec));
						}
					}
				}
			}
		}
	}
	ans = cnt;
	ans /= 16;
	ans = sqrt(ans);
	printf("%.12lf\n", ans);
}
int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	while (cin >> tri[0].X >> tri[0].Y) {
		work();
	}
	return 0;
}
