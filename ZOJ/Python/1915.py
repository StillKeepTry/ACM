c = int(raw_input())
while c:
	c = c - 1
	a = raw_input().split()
	n = int(a[0])
	cnt = s = 0

	for i in range(1, n+1):
		s = s + int(a[i])
	for i in range(1, n+1):
		if (int(a[i]) * n > s):
			cnt = cnt + 1
	cnt = cnt * 100
	ans = float(cnt) / float(n)
	print "%.3lf%%" % ans
