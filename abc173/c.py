h, w, k = map(int, input().split())
board = [list(input()) for _ in range(h)]

ans = 0
for i in range(1 << h):
    for j in range(1 << w):
        cnt = 0
        for y in range(h):
            for x in range(w):
                if i >> y & 1:
                    continue
                if j >> x & 1:
                    continue
                if board[y][x] == '#':
                    cnt += 1
        if cnt == k:
            ans += 1
print(ans)
