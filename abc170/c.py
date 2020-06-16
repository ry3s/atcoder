x, n = map(int, input().split())
ps = list(map(int, input().split()))

st = set(ps)

for i in range(100):
    if x - i not in st:
        print(x - i)
        exit(0)
    elif x + i not in st:
        print(x + i)
        exit(0)
