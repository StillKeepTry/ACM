/*************************************************************************
	> File Name: Kuhn_Munkres(AdjacencyMatrix).cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年07月03日 星期四 19时48分42秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
const int INF = 0x3fffffff;
int g[MAXN][MAXN], nx, ny, match;
int slack[MAXN], lx[MAXN], ly[MAXN], fx[MAXN], fy[MAXN], sx[MAXN], sy[MAXN];

int path(int u)
{
    sx[u] = 1;
    for (int v = 1; v <= ny; v ++) {
        if (sy[v]) continue;
        if (g[u][v] == lx[u] + ly[v]) {
            sy[v] = 1;
            if (!fy[v] || path(fy[v])) {
                fx[u] = v; fy[v] = u;
                return 1;
            }
        } else {
            slack[v] = (slack[v] < (lx[u] + ly[v] - g[u][v])) ? slack[v] : (lx[u] + ly[v] - g[u][v]);
        }
    }
    return 0;
}

int KuhnMunkres()
{
    match = 0;
    memset(lx, 0, sizeof(lx)); memset(ly, 0, sizeof(ly));
    memset(fx, 0, sizeof(fx)); memset(fy, 0, sizeof(fy));
    for (int i = 1; i <= nx; i ++) {
        lx[i] = - INF;
        for (int j = 1; j <= ny; j ++) {
            lx[i] = (lx[i] < g[i][j]) ? g[i][j] : lx[i];
        }
    }
    for (int i = 1; i <= nx; i ++) {
        for (int j = 1; j <= ny; j ++) slack[j] = INF;
        if (!fx[i]) {
            memset(sx, 0, sizeof(sx)); memset(sy, 0, sizeof(sy));
            while (!path(i)) {
                int p = INF;
                for (int j = 1; j <= ny; j ++) {
                    if (!sy[j] && p > slack[j]) p = slack[j];
                }
                for (int j = 1; j <= nx; j ++) if (sx[j]) lx[j] -= p, sx[j] = 0;
                for (int j = 1; j <= ny; j ++) if (sy[j]) ly[j] += p, sy[j] = 0;
            }
        }
    }
    for (int i = 1; i <= ny; i ++) {
        match += g[fy[i]][i];
    }
    return match;
}
