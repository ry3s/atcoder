k, n = map(int, input().split())
arr = list(map(int, input().split()))

prev = arr[0]
maxi = 0
sums = 0
for a in arr[1:]:
    sums += a - prev
    maxi = max(maxi, a - prev)
    prev = a

sums += k - (arr[-1] - arr[0])
maxi = max(maxi,  k - (arr[-1] - arr[0]))
print(sums - maxi)
