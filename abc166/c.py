n, m = map(int, input().split())
hs = list(map(int, input().split()))

graph = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)

ans = 0
for i in range(n):
    h = hs[i]
    maxi = 0
    for x in graph[i]:
        maxi = max(hs[x], maxi)

    if h > maxi:
        ans += 1

print(ans)
