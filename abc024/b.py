n, t = map(int, input().split())
a_arr = [int(input()) for _ in range(n)]

now = a_arr[0]
ans = 0
for a in a_arr[1:]:
    if a - now < t:
        ans += a - now
    else:
        ans += t

    now = a

print(ans + t)
