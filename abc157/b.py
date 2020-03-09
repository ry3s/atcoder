a = []
for _ in range(3):
    a.append(list(map(int, input().split())))

n = int(input())
b = [int(input()) for _ in range(n)]

for x in b:
    for i in range(3):
        for j in range(3):
            if a[i][j] == x:
                a[i][j] = -1

for i in range(3):
    ok = True
    for j in range(3):
        if a[i][j] != -1:
            ok = False

    if ok:
        print("Yes")
        exit(0)

for j in range(3):
    ok = True
    for i in range(3):
        if a[i][j] != -1:
            ok = False
    if ok:
        print("Yes")
        exit(0)

if a[0][0] == -1 and a[1][1] == -1 and a[2][2]:
    print("Yes")
    exit(0)
if a[2][0] == -1 and a[1][1] == -1 and a[0][2]:
    print("Yes")
    exit(0)

print("No")
