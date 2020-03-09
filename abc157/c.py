n, m = map(int, input().split())
arr = []
for _ in range(m):
    arr.append(list(map(int, input().split())))

ans = ['0'] * n
for s, c in arr:
    ans[s - 1] = chr(c)

flag = False
