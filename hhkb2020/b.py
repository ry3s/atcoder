h, w = map(int, input().split())
s = [input() for _ in range(h)]

cnt = 0
for y in range(h - 1):
    for x in range(w):
        if s[y][x] == '.' and s[y + 1][x] == '.':
            cnt += 1

for y in range(h):
    for x in range(w - 1):
        if s[y][x] == '.' and s[y][x + 1] == '.':
            cnt += 1

print(cnt)
