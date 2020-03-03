n = int(input())
xs = list(map(int, input().split()))

ans = 1000000
for p in range(1, 101):
    hp_sum = 0
    for x in xs:
        hp_sum += (x - p) ** 2
    ans = min(ans, hp_sum)

print(ans)
