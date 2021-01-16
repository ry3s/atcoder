import math

n = int(input())
A = list(map(int, input().split()))

cnt = 0
ans = 0
for k in range(2, 1000 + 1):
    sm = 0
    for a in A:
        if a % k == 0:
            sm += 1
    if cnt < sm:
        cnt = sm
        ans = k
print(ans)
