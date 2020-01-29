x = input()
i = 0
while i < len(x):
    if x[i] == 'o' or x[i] == 'k' or x[i] == 'u':
        i += 1
    elif i + 1 < len(x) and x[i:i + 2] == 'ch':
        i += 2
    else:
        print("NO")
        exit(0)

print("YES")
