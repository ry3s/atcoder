n = int(input())
a = list(map(int, input().split()))

ans = 0
cnt = 0
for x in a:
    if x != 0:
        ans += x
        cnt += 1

print((ans + cnt - 1) // cnt)
