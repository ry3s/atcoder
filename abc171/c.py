n = int(input())

ans = ""
while n > 0:
    x = n % 26
    if x != 0:
        ans += chr(x + 96)
    else:
        ans += 'z'
        n -= 1

    n = n // 26

print(ans[::-1])
