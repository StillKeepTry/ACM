/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: b.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月19日 星期三 23时46分53秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
double a, d;
int n, pos, dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct point {
	double x, y;
}o;
bool islegal()
{
	if (o.x >= 0 && o.x <= a && o.y >= 0 && o.y <= a) {
		return true;
	}
	return false;
}
void move()
{
	o.x += d * dir[pos][0];
	o.y += d * dir[pos][1];
	while (!islegal()) {
		if (pos == 0) {
			o.y = o.x - a;
			o.x = a;
		} else if (pos == 1) {
			o.x = o.x - o.y + a;
			o.y = a;
		} else if (pos == 2) {
			o.y = a + o.x;
			o.x = 0;
		} else {
			o.x = 0 - o.y;
			o.y = 0;
		}
		pos = (pos + 1) % 4;
	}
}
void work()
{
	cin >> n;
	o.x = o.y = 0;
	while (d >= 4*a) {
		d -= 4*a;
	}
	pos = 0;
	for (int i = 1; i <= n; i ++) {
		move();
		printf("%.6lf %6lf\n", o.x, o.y);
	}
}
int main()
{
	while (cin >> a >> d) {
		work();
	}
    return 0;
}
