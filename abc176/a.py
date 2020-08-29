n, x, t = map(int, input().split())

time = 0
cnt = 0
while cnt < n:
    time += t
    cnt += x

print(time)
