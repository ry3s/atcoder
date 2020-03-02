n, k = map(int, input().split())
ps = list(map(int, input().split()))

acc = [0]
for p in ps:
    acc.append(acc[-1] + p)

ans = 0.0
for i in range(1, n - k - 1):
    ans = max(ans, (acc[i + k] - acc[i]) / k)

print(ans)
