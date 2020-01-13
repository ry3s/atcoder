n, a, b = map(int, input().split())
queries = []
for _ in range(n):
    s, d = input().split()
    queries.append((s, int(d)))

ans = 0
for s, d in queries:
    direction = 0
    if s == 'East':
        direction = 1
    else:
        direction = -1

    if d < a:
        ans += direction * a
    elif d > b:
        ans += direction * b
    else:
        ans += direction * d

if ans == 0:
    print(0)
elif ans > 0:
    print("East", ans)
else:
    print("West", abs(ans))
