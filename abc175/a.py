s = input()

ans = 0
for ch in s:
    if ch == 'R':
        ans += 1

if ans == 2 and s[1] == 'S':
    print(1)
else:
    print(ans)
