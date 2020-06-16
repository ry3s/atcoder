n = int(input())
arr = list(map(int, input().split()))

if 0 in arr:
    print(0)
    exit(0)

prod = 1
for a in arr:
    prod *= a
    if prod > 1000000000000000000:
        print(-1)
        exit(0)

print(prod)
