/*************************************************************************
	> File Name: fft.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月11日 星期一 18时21分19秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-6
#define PI acos(-1.0)
#define cp complex<double>
#define MAXN 400005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef vector <int> vi;
typedef vector <cp> vcp;
int N, NA, NB, a[MAXN], b[MAXN];
LL ans[MAXN];
cp A[MAXN], B[MAXN], Y1[MAXN], Y2[MAXN], C[MAXN], Y[MAXN];

/*
 * 输入说明：输入 NA, NB。分别表示A数组有NA + 1项， B数组有NB + 1项
 * 接下来为 NA + 1 个数表示A数组从第NA项～第0项的系数
 * 接下来为 NB + 1 个数表示B数组从第NB项～第0项的系数
 */
void input() {
    for (int i = 0; i <= NA; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= NB; i ++) {
        scanf("%d", &b[i]);
    }
    NA ++, NB ++;
    reverse(a, a + NA);
    reverse(b, b + NB);
}

/*
 * 将A和B的系数调整相同
 * 将多项式A和B的次数级扩充到2*n
 * 2*n为2的幂次方
 */
void Extend() {
    N = Max(NA, NB);
    N = 1 << (int)(ceil(log(2.0 * N) / log(2.0) - eps));
    for (int i = NA; i < N; i ++) a[i] = 0;
    for (int i = NB; i < N; i ++) b[i] = 0;
    NA = NB = N;
    for (int i = 0; i < N; i ++) {
        A[i] = cp(a[i], 0);
        B[i] = cp(b[i], 0);
    }
}

/*
 * 快速傅立叶
 * 时间复杂度: O(NlogN)
 * One 为 1表示顺时针
 * One 为-1表示逆时针
 */
void FFT(cp *a, int n, int One, cp *y) {
    if (n == 1) {
        y[0] = a[0]; return ;
    }
    cp w = cp(1, 0), wn = cp(cos(One * 2 * PI / n), sin(One * 2 * PI / n));
    cp *a1 = new cp[n / 2], *a2 = new cp[n / 2];
    cp *y1 = new cp[n / 2], *y2 = new cp[n / 2];
    for (int i = 0; i < n / 2; i ++) a1[i] = a[2 * i], a2[i] = a[2 * i + 1]; 
    FFT(a1, n / 2, One, y1);
    FFT(a2, n / 2, One, y2);
    for (int i = 0; i < n / 2; i ++) {
        y[i] = y1[i] + w * y2[i];
        y[i + n / 2] = y1[i] - w * y2[i];
        w *= wn;
    }
    delete a1; delete a2; delete y1; delete y2;
}

/*
 * 点乘
 */
void Dot()
{
    for (int i = 0; i < N; i ++) {
        C[i] = Y1[i] * Y2[i];
    }
}

void work()
{
    input();
    Extend();
    FFT(A, N, 1, Y1); 
    FFT(B, N, 1, Y2);
    Dot();
    FFT(C, N, -1, Y);
    /*
     * Complex 是double，所以，必须要跟精度转化为int
     */
    for (int i = 0; i < N; i ++) {
        ans[i] = (LL)ceil(Y[i].real() - eps) / N;
    } 
    while (N > 0 && !ans[N - 1]) {
        N --;
    }
    for (int i = 0; i < N; i ++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}
int main()
{
    freopen("fft.in", "r", stdin);
    freopen("fft.out", "w", stdout);
    while (scanf("%d %d", &NA, &NB) != EOF) {
        work();
    }
    return 0;
}
