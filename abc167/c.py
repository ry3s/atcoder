n, m, x = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]

maxi = 10 ** 5 * 12 + 1
ans = maxi

for bits in range(1, 2 ** n):
    scores = [0 for _ in range(m)]
    cost = 0
    for i in range(n):
        if bits >> i & 1:
            cost += arr[i][0]
            for j in range(m):
                scores[j] += arr[i][j + 1]

    if min(scores) >= x:
        ans = min(ans, cost)

print(ans if ans != maxi else -1)
