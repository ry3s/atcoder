n = int(input())

cases = ['AC', 'WA', 'TLE', 'RE']
ans = [0, 0, 0, 0]
for _ in range(n):
    s = input()
    for i, case in enumerate(cases):
        if s == case:
            ans[i] += 1

for i in range(4):
    print("{} x {}".format(cases[i], ans[i]))
