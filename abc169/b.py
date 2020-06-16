n = int(input())
arr = list(map(int, input().split()))

while len(arr) > 1:
    m = len(arr)
    if m & 1:
        arr.append(1)
        m += 1

    left, right = arr[:m // 2], arr[m // 2:]
    arr = [x * y for x, y in zip(left, right)]

x = arr[0]
if x > 10 ** 18:
    print(-1)
else:
    print(x)
