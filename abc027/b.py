n = int(input())
a = list(map(int, input().split()))

sum = sum(a)

if sum % n > 0:
    print(-1)
else:
    avg = sum / n
    total = 0
    count = 0
    ans = 0
    for x in a:
        total += x
        count += 1
        if total != avg * count:
            ans += 1

    print(ans)
