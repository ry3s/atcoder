n, d = map(int, input().split())

xys = [tuple(map(int, input().split())) for _ in range(n)]
ans = 0
d = d * d
for x, y in xys:
    if x * x + y * y <= d:
        ans += 1

print(ans)
