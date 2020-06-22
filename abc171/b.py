n, k = map(int, input().split())
ps = list(map(int, input().split()))

ps.sort()
ans = sum(ps[:k])
print(ans)
