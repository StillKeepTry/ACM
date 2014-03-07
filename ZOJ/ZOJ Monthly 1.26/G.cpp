/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    > File Name: c.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年01月26日 星期日 15时31分19秒
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
using namespace std;
#define LL long long 
#define MAXN 106
#define x first
#define y second
template<typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
LL a, b, m, cnt, ansx, ansy;
vector <LL> fact, di;
PII d[MAXN];
LL gcd(LL a, LL b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
LL lcm(LL a, LL b)
{
	return a * b / gcd(a, b);
}
LL MOD_Mult(LL a, LL b, LL n)
{
	LL ans = 0;
	a = a % n;
	while (b) {
		if (b & 1) {
			ans += a;
			if (ans >= n) {
				ans -= n;
			}
		}
		a <<= 1;
		if (a >= n)
			a -= n;
		b >>= 1;
	}
	return ans;
}
LL power_mod(LL a, LL b, LL n)
{
	LL d = 1;
	a %= n;
	while (b) {
		if(b & 1) d = MOD_Mult(d,a,n);
		a = MOD_Mult(a,a,n);
		b >>= 1;
	}
	return d;
}
bool witness(LL a,LL n)//以a为底，测试n是不是素数,a^(n-1) == 1 (mod n)
{
	LL m,x,y;
	int j = 0;
	m = n - 1;
	while(!(m & 1)) {
		m >>= 1;
		j ++;
	}
	x = power_mod(a,m,n);
	for(int i = 1; i <= j; i ++)
	{
		y = power_mod(x,2,n);
		if((y == 1) && (x != 1) && (x != n-1))
			return false;
		x = y;
	}
	if(y != 1) {
		return false;
	}
	return true;
}
bool miller_rabbin(int test,LL n)
{
	LL a;
	if(n == 1) return false;
	if(n == 2) return true;
	if(!(n & 1)) return false;
	srand(time(NULL));
	for(int i = 1; i <= test; i ++) {
		a = rand() % (n-1) + 1;
		if(!witness(a,n)) {
			return false;
		}
	}
	return true;
}
LL pollard_rho(LL c,LL n)
{
	LL i,x,y,k,d;
	i = 1;
	x = y = rand() % n;
	k = 2;
	do {
		i ++;
		d = gcd(n+y-x, n);
		if (d > 1 && d < n) return d;
		if (i == k) {
			y = x;
			k <<= 1;
		}
		x = (MOD_Mult(x,x,n) + n - c) % n;
	} while (y != x);
	return n;
}
void rho(LL n)
{
	if (n == 1) return ;
	if(miller_rabbin(10,n)) {
		fact.push_back(n);
		return ;
	}
	LL t = n;
	while(t >= n)
		t = pollard_rho(rand() % (n-1) + 1,n);
	rho(t);
	rho(n/t);
}
void dfs(LL now, int len)
{
	if (len > cnt) {
		di.push_back(now);
		return ;
	}
	dfs(now, len+1);
	for (int i = 0; i < d[len].y; i ++) {
		now *= d[len].x;	
		dfs(now, len+1);
	}
}
void work()
{
	memset(d, 0, sizeof(d));
	fact.clear();
	di.clear();
	LL p = a * b;
	rho(p);
	sort(fact.begin(), fact.end());
	cnt = 0;
	for (int i = 0; i < fact.size(); i ++) {
		if (i == 0) {
			d[cnt].x = fact[i];
			d[cnt].y ++;
		} else {
			if (fact[i] == fact[i-1]) {
				d[cnt].y ++;
			} else {
				cnt ++;
				d[cnt].x = fact[i];
				d[cnt].y ++;
			}
		}
	}
	dfs(1, 0);
	sort(di.begin(), di.end());
	ansx = 0, ansy = 0;
	for (int i = 0; i < di.size(); i ++) {
		if (di[i] + b >= m) {
			if (ansx == 0 && ansy == 0) {
				ansx = di[i], ansy = p / di[i];
			} else {
				LL tmp = di[i] + p / di[i];
				if (ansx + ansy > tmp) {
					ansx = di[i], ansy = p / di[i];
				} 
			}
		}
	}
	if (ansx && ansy) {
		printf("%lld %lld\n", ansx+b, ansy+a);
	} else {
		printf("No answer\n");
	}
}
int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	while (scanf("%lld %lld %lld", &a, &b, &m) != EOF) {
		work();
	}
    return 0;
}
