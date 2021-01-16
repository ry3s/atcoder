a, b = map(int, input().split())
maxi = 2 * a + 100
ans = max(0, maxi - b)
print(ans)
