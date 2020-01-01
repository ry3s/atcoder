n = int(input())

a = [[i, int(input())] for i in range(n)]

a_sorted = sorted(a, key=lambda x: x[1])

prev = a_sorted[0][1]
cnt = 0
for i in range(n):
    index, x = a_sorted[i]
    if x == prev:
        a_sorted[i][1] = cnt
    else:
        cnt += 1
        a_sorted[i][1] = cnt
        prev = x

a_sorted.sort(key=lambda x: x[0])

for x in a_sorted:
    print(x[1])
