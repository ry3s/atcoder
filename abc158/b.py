n, a, b = map(int, input().split())
if a == 0:
    print(0)
elif n <= a:
    print(n)
else:
    div = n // (a + b)
    rem = n % (a + b)
    if rem <= a:
        print(div * a + rem)
    else:
        print(div * a + a)
