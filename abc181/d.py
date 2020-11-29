from collections import Counter

s = input()

if len(s) <= 2:
    if int(s) % 8 == 0 or int(s[::-1]) % 8 == 0:
        print("Yes")
    else:
        print("No")
    exit()

cnt = Counter(s)
for x in range(112, 1000, 8):
    if not Counter(str(x)) - cnt:
        print("Yes")
        exit()

print("No")
