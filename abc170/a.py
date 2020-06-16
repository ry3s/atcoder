xs = list(map(int, input().split()))

for i in range(5):
    if xs[i] == 0:
        print(i + 1)
        exit(0)
