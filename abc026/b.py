import math
n = int(input())
rs = [int(input()) for _ in range(n)]

rs.sort()
rs.reverse

ans = 0
for i, r in enumerate(rs):
    square = r * r
    if i % 2 == 0:
        ans += square
    else:
        ans -= square

print(math.pi * abs(ans))
