s = input()
n = int(input())

count = 0
for c1 in s:
    for c2 in s:
        count += 1
        if count == n:
            print(c1 + c2)
            exit(0)
