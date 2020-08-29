n = int(input())
A = list(map(int, input().split()))

prev = 0
ans = 0
for a in A:
    if a < prev:
       ans += prev - a

    prev = max(prev, a)

print(ans)
