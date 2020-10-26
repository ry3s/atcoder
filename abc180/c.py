n = int(input())

divs = []
for i in range(1, int(n ** 0.5) + 1):
    if n % i == 0:
        divs.append(i)
        if i != n // i:
            divs.append(n // i)
divs.sort()
for d in divs:
    print(d)
