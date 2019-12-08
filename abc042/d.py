h, w, a, b = map(int, input().split())  # 入力
mod = 10**9+7

# 前計算　f[i] = i!
f = [1]
for i in range(h+w):
    f.append(f[i]*(i+1) % mod)

# C(n,r,p) = ( n! * r!^(p-2) * (n-r)!^(p-2) )%p
# pythonだとpow()で二分累乗法が使える


def comb(n, r, p):
    return f[n] * pow(f[r], p-2, p) * pow(f[n-r], p-2, p) % p

# 紫点ごとに調べる


ans = 0
for i in range(b, w):
    ans += comb(h+i-a-1, i, mod) * comb(w-1-i+a-1, a-1, mod) % mod

print(ans % mod)
