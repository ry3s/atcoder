import fractions
n = int(input())


d = {}
for _ in range(n):
    a, b = map(int, input().split())
    x = fractions.Fraction(a, b)
    y = fractions.Fraction(b, a)
    if x not in d:
        d[x] = d[x] + 1
    else:
        d[x] = 1

    if y not in d:
        d[y] = d[y] + 1
    else:
        d[y] = 1

ans = 0
for key, value in d.items():
    if -key in d:
        ans += d[key] * d[-key] // 2

print(ans)
