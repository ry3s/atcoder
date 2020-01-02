n = int(input())

s = []
p = []
for i in range(n):
    x, y = input().split()
    s.append(x)
    p.append(int(y))

mean = sum(p) // 2

ok = False
for i in range(n):
    if p[i] > mean:
        print(s[i])
        ok = True
        break

if not ok:
    print("atcoder")
