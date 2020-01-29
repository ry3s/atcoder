arr = [(int(input()), i) for i in range(3)]

arr.sort(key=lambda x: -x[0])
ans = [0, 0, 0]
for i, a in enumerate(arr):
    ans[a[1]] = i + 1

for a in ans:
    print(a)
