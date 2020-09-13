x, k, d = map(int, input().split())

x = -x if x <= 0 else x

if x - d * k >= 0:
    print(x - d * k)
else:
    a = x // d
    b = a + 1
    rest_cnt = k - a
    if rest_cnt % 2 == 0:
        print(abs(x - d * a))
    else:
        print(abs(x - d * b))
