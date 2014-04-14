/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: d.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月20日 星期四 01时14分06秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 1000005
string line;
int dp[MAXN][4], len;
void work()
{
	memset(dp, 0, sizeof(dp));
	len = line.size();
	for (int i = 2; i < len; i ++) {
		int j = i + 1;
		if (line[i] == "?") {
			
		} else if (line[i] == "*") {

		} else if (line[i] == "0") {

		} else if (line[i] == "1") {
			
		} else if (line[i] == "2") {
			
		}
		for (int k = 0; k < 4; k ++) dp[j][k] %= MOD;
	}
}
int main()
{
	while (cin >> line) {
		work();
	}
    return 0;
}
