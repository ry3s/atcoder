k = int(input())
a, b = map(int, input().split())

for i in range(a, b + 1):
    if i % k == 0:
        print("OK")
        exit(0)

print("NG")
