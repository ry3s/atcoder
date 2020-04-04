n, x, y = map(int, input().split())

ans = [0] * n
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        ans[min(j - i, min(abs(i - x) + 1 + abs(y - j),
                           abs(i - y) + 1 + abs(x - j)))] += 1

for x in ans[1:]:
    print(x)
