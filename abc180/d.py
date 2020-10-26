x, y, a, b = map(int, input().split())

ans = 0
cnt = 0
while x < y:
    tmp = cnt + (y - x - 1) // b
    ans = max(ans, tmp)
    if x >= (y + a - 1) // a:
        break
    x *= a
    cnt += 1
print(ans)
