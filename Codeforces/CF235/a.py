line = raw_input().split()
n, x, s = int(line[0]), int(line[1]), 0
line = raw_input().split()
for i in range(0, n):
	s = s + int(line[i])
s = abs(s)
ans = s / x
if (s % x != 0):
	ans = ans + 1
print ans
