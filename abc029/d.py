n = int(input())

m = n
digit_count = 0
while m != 0:
    m //= 10
    digit_count += 1

ans = 0
for i in range(1, digit_count + 1):
    # 1: 0123456789012345678901...
    # 2: 0000000000111111111122
    # i 桁目に注目したとき11111....のパターンの
    # 長さ 10 ** (i - 1)
    # 回数 n // 10 ** i
    # 最後は b 回
    a = (n // pow(10, i)) * pow(10, i - 1)
    b = n % pow(10, i)

    if b >= 2 * pow(10, i - 1):
        b = pow(10, i - 1)
    elif b < pow(10, i - 1):
        b = 0
    else:
        b = b - pow(10, i - 1) + 1

    ans += a + b

print(ans)
