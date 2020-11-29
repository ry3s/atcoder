n = int(input())

ans = 0
for i in range(n):
    a, b = map(int, input().split())
    x = (a - 1) * a // 2
    y = b * (b + 1) // 2
    ans += y - x

print(ans)
