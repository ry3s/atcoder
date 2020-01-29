arr = [list(map(int, input().split())) for _ in range(3)]

ans = 0
for s, e in arr:
    ans += s * e // 10

print(ans)
