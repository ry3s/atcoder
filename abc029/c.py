n = int(input())

ans = []
for bit in range(pow(3, n)):
    mask = bit
    res = ''

    for _ in range(n):
        if mask % 3 == 0:
            res += 'a'
        elif mask % 3 == 1:
            res += 'b'
        else:
            res += 'c'

        mask = mask // 3

    ans.append(res)

ans.sort()

for s in ans:
    print(s)
