import sys

def printNum(a):
	print "%.8lf" % float(a),

n = int(raw_input())
a = [[]] * n
for i in range(0, n):
	a[i] = raw_input().split()
for i in range(0, n):
	for j in range(0, n):
		d = int(a[i][j]) + int(a[j][i])
		d = float(d)
		d = d / 2
		printNum(d)
	print
for i in range(0, n):
	for j in range(0, n):
		d = int(a[i][j]) - int(a[j][i])
		d = float(d)
		d = d / 2
		printNum(d)
	print
