n = int(input())
As = list(map(int, input().split()))

MOD = 1_000_000_007

csum = [0] * (n + 1)
for i in range(n):
    csum[i + 1] = csum[i] + As[i]

ans = 0
for i in range(n - 1):
    ans += As[i] * (csum[n] - csum[i + 1]) % MOD

print(ans % MOD)
