import math
a, b, n = map(int, input().split())

# for i in range(n + 1):
#     x = math.floor((a * i) / b) - a * math.floor(i / b)
#     print(i, x)


if n < b:
    print((a * n) // b - a * (n // b))
else:
    print((a * (b - 1)) // b)
