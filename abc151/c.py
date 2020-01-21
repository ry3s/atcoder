n, m = map(int, input().split())
arr = []

for _ in range(m):
    p, s = input().split()
    arr.append((int(p), s))

ans = [[0, 0] for _ in range(n)]
for p, s in arr:
    if s == 'AC':
        ans[p - 1][0] = 1
    else:
        if ans[p - 1][0] == 0:
            ans[p - 1][1] += 1

oks = 0
ngs = 0
for ok, ng in ans:
    if ok == 1:
        oks += 1
        ngs += ng

print(oks, ngs)
