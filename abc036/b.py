n = int(input())

ss = [list(input()) for _ in range(n)]

ans = [[None] * n for _ in range(n)]


for i in range(n):
    for j in range(n):
        ans[j][n - 1 - i] = ss[i][j]

for i in range(n):
    for j in range(n):
        print(ans[i][j], end="")

    print()
