n = int(input())
arr = []
for _ in range(n):
    x, y = map(int, input().split())
    arr.append([x, y])

ok = False
for i in range(n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            dx1 = arr[j][0] - arr[i][0]
            dy1 = arr[j][1] - arr[i][1]
            dx2 = arr[k][0] - arr[i][0]
            dy2 = arr[k][1] - arr[i][1]
            if dx2 * dy1 == dx1 * dy2:
                ok = True
                break

print("Yes" if ok else "No")
