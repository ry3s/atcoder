n, s, t = map(int, input().split())
w = int(input())
arr = [int(input()) for _ in range(n - 1)]

count = 1 if w >= s and w <= t else 0
cur = w
for a in arr:
    cur += a
    if cur >= s and cur <= t:
        count += 1

print(count)
