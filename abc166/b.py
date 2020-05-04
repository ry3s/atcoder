n, k = map(int, input().split())

arr = []
for _ in range(k):
    d = int(input())
    a = list(map(int, input().split()))
    arr.append(a)

oks = [False] * n
for xs in arr:
    for x in xs:
        oks[x - 1] = True

ans = 0
for x in oks:
    if x == False:
        ans += 1

print(ans)
