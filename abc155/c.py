n = int(input())
mp = dict()
maxi = 0
for _ in range(n):
    s = input()
    if s in mp:
        mp[s] += 1
    else:
        mp[s] = 1
    maxi = max(maxi, mp[s])

ans = []
for x in mp.items():
    if x[1] == maxi:
        ans.append(x[0])

ans.sort()
for x in ans:
    print(x)
