/*************************************************************************
	> File Name: CalcPolygonAreaBing.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月30日 星期一 20时37分00秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;
#define LL long long
#define eps 1e-8
#define MAXN 55
#define M 305
template <typename T> inline T Sqr(T a) {return a * a;}
struct point {
    double x, y;

    point() {}

    point(double _x, double _y) : x(_x), y(_y) {}

    point operator + (const point &p) const {
        return point(x + p.x, y + p.y);
    }

    point operator - (const point &p) const {
        return point(x - p.x, y - p.y);
    }

    point operator * (const double &p) const {
        return point(x * p, y * p);
    }

    double operator * (const point &p) const {
        return x * p.x + y * p.y; 
    }

    point operator / (const double &p) const {
        return point (x / p, y / p);
    }
    
    double operator ^ (const point &p) const {
        return x * p.y - y * p.x;
    }

    bool operator == (const point &p) const {
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }

    bool operator < (const point &p) const {
        if (y == p.y) return x - p.x;
        return y - p.y;
    }

    double getRatio(point &a, point &b) const {
        if (fabs(b.x - a.x) < eps) return (y - a.y) / (b.y - a.y);
        return (x - a.x) / (b.x - a.x);
    }
};

double xmult(point p1, point p2, point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double dmult(point p1, point p2, point p0)
{
    return (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y);
}

struct Polygon2D {
    int n, bn;
    point p[MAXN], bag[MAXN];

    double getArea() {
        double area = 0;
        for (int i = 2; i < bn; i ++) {
            area += xmult(bag[i], bag[i-1], bag[0]);
        }
        return fabs(area / 2.0);
    }

    void setOrder() {
        int i, j, di, st, dt;
        for (i = 0; i < n - 2 && fabs((p[i + 1] - p[i]) ^ (p[i + 2] - p[i])) < eps; i ++) ;
        di = ((p[i + 1] - p[i]) ^ (p[i + 2] - p[i])) > eps ? 1 : -1;
        for (i = di > 0 ? 0 : n - 1, j = 0; i < n && i >= 0; i += di, j ++) {
            bag[j] = p[i];
        }
        bag[bn = j] = bag[0];
    }
};

struct Polygon {
    int n;
    Polygon2D pSet[M];
    pair<double, int> buf[M * MAXN];

    int FSGN(double x) {
        if (x > eps) return 1;
        if (x >= -eps) return 0;
        return -1;
    }

    double getCombination() {
        for (int i = 0; i < n; i ++) {
            pSet[i].setOrder();
        }
        
        if (n == 1) {
            return pSet[0].getArea();
        }
        int cnt, c1, c2;
        double s1, s2, ret = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < pSet[i].bn; j ++) {
                cnt = 0;
                buf[cnt ++] = make_pair(0.0, 0);
                buf[cnt ++] = make_pair(1.0, 0);
                for (int k = 0; k < n; k ++) {
                    if (i == k) continue;
                    for (int q = 0; q < pSet[k].bn; q ++) {
                        c1 = FSGN((pSet[i].bag[j + 1] - pSet[i].bag[j]) ^ (pSet[k].bag[q] - pSet[i].bag[j]));
                        c2 = FSGN((pSet[i].bag[j + 1] - pSet[i].bag[j]) ^ (pSet[k].bag[q + 1] - pSet[i].bag[j]));
                        if (!c1 && !c2) {
                            if (((pSet[i].bag[j + 1] - pSet[i].bag[j]) * (pSet[k].bag[q + 1] - pSet[k].bag[q])) > 0 && i > k) {
                                buf[cnt ++] = make_pair(pSet[k].bag[q].getRatio(pSet[i].bag[j], pSet[i].bag[j + 1]), 1);
                                buf[cnt ++] = make_pair(pSet[k].bag[q + 1].getRatio(pSet[i].bag[j], pSet[i].bag[j + 1]), -1);
                            }
                        } else {
                            s1 = ((pSet[k].bag[q + 1] - pSet[k].bag[q]) ^ (pSet[i].bag[j] - pSet[k].bag[q]));
                            s2 = ((pSet[k].bag[q + 1] - pSet[k].bag[q]) ^ (pSet[i].bag[j + 1] - pSet[k].bag[q]));
                        }
                        if (c1 >= 0 && c2 < 0) buf[cnt ++] = make_pair(s1 / (s1 - s2), 1);
                        else if (c1 < 0 && c2 >= 0) buf[cnt ++] = make_pair(s1 / (s1 - s2), -1);
                    }
                }
                sort (buf, buf + cnt);
                double pre = min(max(buf[0].first, 0.0), 1.0), now, sum = 0, cov = buf[0].second;
                for (int k = 1; k < cnt; k ++) {
                    now = min(max(buf[k].first, 0.0), 1.0);
                    if (!cov) sum += now - pre;
                    cov += buf[k].second;
                    pre = now;
                }
                ret += (pSet[i].bag[j] ^ pSet[i].bag[j + 1]) * sum;
            }
        }
        return fabs(ret / 2.0);
    }
};
