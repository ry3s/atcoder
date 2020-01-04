n = int(input())
a = list(map(int, input().split()))

ans = (- 2 ** 32, - 2 ** 32)
for i in range(n):
    fst_best = - 2 ** 32
    snd_best = - 2 ** 32
    for j in range(n):
        if i == j:
            continue

        l, r = min(i, j), max(i, j) + 1
        fst, snd = 0, 0
        for k in range(l, r):
            if (k - l) % 2 == 0:
                fst += a[k]
            else:
                snd += a[k]

        if snd_best < snd:
            fst_best = fst
            snd_best = snd

    ans = max(ans, (fst_best, snd_best))

print(ans[0])
