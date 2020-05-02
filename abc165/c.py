n, m, q = map(int, input().split())

perm = []
def f(i, cur, res):
    if i == n:
        perm.append(res)
    else:
        res.append(cur)
        for x in range(cur, m + 1):
            f(i + 1, x, res)

print(perm)
arr = []
for _ in range(q):
    a, b, c, d = map(int, input().split())
    arr.append((a, b, c, d))
