s = input()

arr = []
for ch in s:
    if len(arr) == 0 or arr[-1][0] != ch:
        arr.append([ch, 1])
    else:
        arr[-1][1] += 1

ans = ""
for x in arr:
    ans += "{}{:d}".format(x[0], x[1])

print(ans)
