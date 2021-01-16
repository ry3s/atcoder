import bisect
n, m = map(int, input().split())
hs = list(map(int, input().split()))
ws = list(map(int, input().split()))

hs.sort()

acc_left = [0] * (n + 1)
acc_right = [0] * (n + 1)
for i in range(2, n, 2):
    acc_left[i] = acc_left[i - 2] + hs[i - 1] - hs[i - 2]
    acc_right[i] = acc_right[i - 2] + hs[n - i + 1] - hs[n - i]

ans = 1 << 60
for w in ws:
    idx = bisect.bisect(hs, w)
    if idx % 2 == 0:
        ans = min(ans, acc_left[idx] + acc_right[n - idx - 1] + hs[idx] - w)
    else:
        ans = min(ans, acc_left[idx - 1] + acc_right[n - idx] + w - hs[idx - 1])
print(ans)
