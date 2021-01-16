n = list(map(int, input()))

ans = len(n)
for bit in range(1 << len(n)):
    acc = 0
    for i in range(len(n)):
        if (bit >> i) & 1:
            acc += n[i]
    if acc == 0:
        continue
    if acc % 3 == 0:
        ans = min(ans, len(n) - bin(bit).count("1"))

print(-1 if ans == len(n) else ans)
