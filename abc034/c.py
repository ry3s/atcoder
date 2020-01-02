mod = 10 ** 9 + 7
N = 2 * 10 ** 5 + 1
fac = [1, 1]
finv = [1, 1]
inv = [0, 1]

for i in range(2, N + 1):
    fac.append(fac[-1] * i % mod)
    inv.append(mod - inv[mod % i] * (mod // i) % mod)
    finv.append((finv[-1] * inv[-1]) % mod)


def cmb(n, r):
    r = min(r, n - r)
    return fac[n] * finv[r] * finv[n - r] % mod


w, h = map(int, input().split())

print(cmb(w + h - 2, h - 1))
