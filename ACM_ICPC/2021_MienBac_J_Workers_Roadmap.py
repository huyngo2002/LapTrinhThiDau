// Link: https://oj.vnoi.info/problem/icpc21_mb_j
class Worker:
	def __init__(self, a, b):
		self.A = a
		self.B = b
n, M = map(int, input().strip().split())
a = []
for i in range(n):
	u, v = map(int, input().strip().split())
	a.append(Worker(u, v))
ans = -1
lo = 1
hi = 10000000000000000007
while lo <= hi:
	mid = (lo + hi) // 2
	total = 0
	for element in a:
		numDays = mid // (element.B + 1)
		rem = mid % (element.B + 1)
		total += numDays * element.A * element.B
		total += rem * element.A
	if total >= M:
		ans = mid
		hi = mid - 1
	else:
		lo = mid + 1
print(ans)
