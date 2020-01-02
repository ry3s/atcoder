n, k = map(int, input().split())
s = [int(input()) for _ in range(n)]

if 0 in s:
    print(n)
else:
    right = 0
    prod = 1
    ans = 0
    for left in range(n):
        while right < n and prod * s[right] <= k:
            prod *= s[right]
            right += 1

        ans = max(ans, right - left)
        if left == right:
            right += 1
        else:
            prod = prod // s[left]

    print(ans)
