/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: d.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年03月02日 星期日 13时29分07秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL now, n, m, a, p, q, ap[2];
void getD(vector<LL> &v, int q)
{	
	int d = 0;
	for (int i = 0; i < q; i ++) {
		cin >> d;
		v.push_back(d);
	}
}
LL MNum(vector<LL> v)
{
	LL ans = 0;
	for (int i = 0; i < v.size(); i ++) {
		if (v[i] > ans) ans = v[i];
	}
	return ans;
}
LL target(set<LL> ball)
{
	set<LL>::iterator it = ball.begin();
	return *it;
}
bool Cue(vector<LL> v)
{
	for (int i = 0; i < v.size(); i ++) {
		if (v[i] == 0) return true;
	}
	return false;
}
LL cal(vector<LL> v)
{
	LL ans = 0;
	for (int i = 0; i < v.size(); i ++) ans += v[i];
	return ans;
}
bool hastarget(vector<LL> v, LL target) 
{
	for (int i = 0; i < v.size(); i ++) {
		if (v[i] == target) return true;
	}
	return false;
}
void del(set<LL> &ball, vector<LL> packet)
{
	for (int i = 0; i < packet.size(); i ++) {
		if (packet[i] > 0) ball.erase(packet[i]);
	}
}	
void work()
{
	static set<LL> ball;
	ball.clear();
	for (LL i = 1; i <= n; i ++) {
		cin >> a;
		ball.insert(a);
	}
	now = ap[0] = ap[1] = 0;
	for (LL i = 1; i <= m; i ++) {
		bool foul = false; 
		vector <LL> hit, packet;
		cin >> p;
		getD(hit, p);
		cin >> q;
		getD(packet, q);
		LL t = target(ball); // now the target
		del(ball, packet);
		if (p == 0) {
			foul = true;
			ap[now^1] += t;
		} else if (!Cue(packet) && p >= 1) { // not packet
			if (p >= 2 || (p == 1 && hit[0] != t)) { // mei you target
				foul = true;
				ap[now^1] += MNum(hit);
			}
		} else if (Cue(packet) && p >= 1) { // packet and hit
			foul = true;
			ap[now^1] += MNum(hit);
		}
		if (hastarget(packet, t) && !foul) { // mei gui
			ap[now] += cal(packet);
		} else { 
			ap[now^1] += cal(packet);	
			now ^= 1;
		}
	}
	cout << ap[0] << " : " << ap[1] << endl;
}
int main()
{
	while (cin >> n >> m) {
		work();
	}
	return 0;
}
