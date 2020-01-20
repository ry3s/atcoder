a, b = map(int, input().split())

x = "".join([str(a)] * b)
y = "".join([str(b)] * a)
if x < y:
    print(x)
else:
    print(y)
