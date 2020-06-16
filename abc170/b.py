x, y = map(int, input().split())

ok = False
for a in range(0, x + 1):
    b = x - a
    if b < 0:
        continue

    if 2 * a + 4 * b == y:
        ok = True

if ok:
    print("Yes")
else:
    print("No")
