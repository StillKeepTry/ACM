/*************************************************************************
	> File Name: a.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com 
	> Created Time: 2014年06月01日 星期日 21时00分28秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int len[4], id;
string a[4];
void work()
{
    for (int i = 1; i < 4; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i ++) {
        len[i] = a[i].length() - 2;
    }
    int cnt = 0;
    for (int i = 0; i < 4; i ++) {
        int flag = 0;
        for (int j = 0; j < 4; j ++) {
            if (i == j) continue;
            if (len[j] < len[i] * 2) {
                flag = 1;
            }
        }
        if (flag == 0) {
            id = i;
            cnt ++;
        }
        flag = 0;
        for (int j = 0; j < 4; j ++) {
            if (i == j) continue;
            if (len[j] * 2 > len[i]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            cnt ++;
            id = i;
        }
    }
    if (cnt == 1) {
        printf("%c\n", 'A' + id);
        return ;
    }
    printf("C\n");
}
int main()
{
    while (cin >> a[0]) {
        work();
    }
	return 0;
}
