n, m = map(int, input().split())
arr = list(map(int, input().split()))

cnt = 0
sm = sum(arr)
for a in arr:
    if a < sm / (4 * m):
        continue
    else:
        cnt += 1

if cnt >= m:
    print("Yes")
else:
    print("No")
