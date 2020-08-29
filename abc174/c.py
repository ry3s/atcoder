k = int(input())

x = 7
for i in range(k):
    if x % k == 0:
        print(i + 1)
        break
    x = (x * 10 + 7) % k
else:
    print(-1)
