n, k = map(int, input().split())

x = n
ans = 0
while x > 0:
    x = x // k
    ans += 1

print(ans)
