n, k, m = map(int, input().split())
arr = list(map(int, input().split()))
sm = sum(arr)
ans = m * n - sm

if ans > k:
    ans = -1
elif ans < 0:
    ans = 0


print(ans)
