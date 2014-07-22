/*************************************************************************
	> File Name: CommonUserd.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月22日 星期二 16时58分02秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define eps 1e-8

struct Point {
    double x, y;
    
    Point() {}

    Point(double x, double y): x(x), y(y) {}

    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator * (const double &p) const {
        return Point(x * p, y * p);
    }

    double operator * (const Point &p) const {
        return x * p.x + y * p.y;
    }

    double operator ^ (const Point &p) const {
        return x * p.y - y * p.x;
    }

    Point operator / (const double &p) const {
        return Point(x / p, y / p);
    }

    bool operator == (const Point &p) const {
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }

    bool operator < (const Point &p) const {
        if (y == p.y) return x - p.x;
        return y - p.y;
    }

    double len() {
        return sqrt(x * x + y * y);
    }

    Point Rotate(double angle) {
        return Point(x * cos(angle) + y * sin(angle), - x * sin(angle) + y * cos(angle));
    }
};

void work()
{

}
int main()
{
    return 0;
}
