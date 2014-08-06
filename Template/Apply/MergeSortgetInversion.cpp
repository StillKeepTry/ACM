/*************************************************************************
	> File Name: MergeSortgetInversion.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年08月06日 星期三 21时23分32秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
#define MAXN 500005
LL a[MAXN], ans, c[MAXN], n;

void MergeSort(int l, int r) 
{
    if (r - l > 1) {
        int mid = (r + l) >> 1;
        MergeSort(l, mid);
        MergeSort(mid + 1, r);
        int tmp = l, i, j;
        for (i = l, j = mid+1; i <= mid && j <= r;) {
            if (a[i] > a[j]) {
                c[tmp ++] = a[j ++];
                ans = ans + mid - i + 1;
            } else {
                c[tmp ++] = a[i ++];
            }
        }
        for (; j <= r; j ++) {
            c[tmp ++] = a[j];
        }
        for (; i <= mid; i ++) {
            c[tmp ++] = a[i];
        }
    } else {
        if (a[r] < a[l]) {
            ans ++;
            c[l] = a[r], c[r] = a[l];
        } else {
            c[l] = a[l], c[r] = a[r];
        }
    }
    for (int i = l; i <= r; i ++) {
        a[i] = c[i];
    }
}
