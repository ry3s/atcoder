a, b, c, k = map(int, input().split())
s, t = map(int, input().split())

discount = c * (s + t) if s + t >= k else 0
ans = s * a + t * b - discount
print(ans)
