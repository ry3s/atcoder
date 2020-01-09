v = list(map(int, input().split()))

ans = []
for i in range(5):
    for j in range(i + 1, 5):
        for k in range(j + 1, 5):
            sums = v[i] + v[j] + v[k]
            ans.append(sums)

ans.sort()
print(ans[-3])
