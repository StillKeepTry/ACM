import sys

def show(a):
	sys.stdout.write(a)

def work():
	s, ts = raw_input().split("|"), raw_input()
	l1, l2, l = len(s[0]), len(s[1]), len(ts)
	if (l1 + l2 + l) % 2 or abs(l1 - l2) > l:
		print "Impossible"
		return 
	else:
		show(ts[:((l1+l2+l) / 2 - l1)])
		show(s[0] + "|" + s[1])
		show(ts[((l1+l2+l) / 2 - l1):])

if __name__ == "__main__":
	work() 