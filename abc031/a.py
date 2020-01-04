a, d = map(int, input().split())

if (a + 1) * d == a * (d + 1):
    print((a + 1) * d)
elif (a + 1) * d > a * (d + 1):
    print((a + 1) * d)
else:
    print(a * (d + 1))
