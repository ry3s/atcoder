def fact(n):
    if n == 0:
        return 1
    else:
        return n * fact(n - 1)

n, m = map(int, input().split())
print(n * (n - 1)//2 + m * (m - 1)//2)
