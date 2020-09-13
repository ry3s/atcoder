n = int(input())
ls = list(map(int, input().split()))

cnt = 0
for i in range(n - 2):
    for j in range(i, n - 1):
        for k in range(j, n):
            a, b, c = ls[i], ls[j], ls[k]
            if a == b or b == c or c == a:
                continue
            if a + b > c and b + c > a and c + a > b:
                cnt += 1

print(cnt)
