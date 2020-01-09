s = input()

ans = [0] * 6
for ch in s:
    ans[ord(ch) - ord('A')] += 1

for i, x in enumerate(ans):
    if i != 5:
        print(x, end=' ')
    else:
        print(x)
