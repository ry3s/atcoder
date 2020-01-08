import bisect

n, m = map(int, input().split())
x, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

time = 0
lp = 0

while True:
    id = bisect.bisect_left(a, time)
    if id >= n:
        break

    time = a[id] + x

    id = bisect.bisect_left(b, time)
    if id >= m:
        break

    time = b[id] + y
    lp += 1

print(lp)
