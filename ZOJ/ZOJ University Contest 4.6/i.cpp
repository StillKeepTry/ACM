/*************************************************************************
    > File Name: i.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年04月06日 星期日 13时46分39秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int t, cnt;
string des, src;
void work()
{
	getline(cin, src);
	des = "";
	for (int i = 0; i < src.length(); i ++) {
		if (src[i] == '!') {
			des = des + "Hello, world!";
		}
	}
	if (des == src) {
		printf("Yes\n");
		return ;
	}
	cnt = 0;
	for (int i = 0; i < src.length(); i ++) {
		if (src[i] == '!') {
			printf("No\n");
			return ;
		}
		if (src[i] == '_') {
			cnt ++;
		}
	}
	if (cnt == 1) {
		printf("Yes\n");
		return ;
	} else {
		printf("No\n");
		return ;
	}
}
int main()
{
	scanf("%d", &t);
	getline(cin, src);
	while (t --) {
		work();
	}
	return 0;
}
