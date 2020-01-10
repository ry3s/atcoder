n = bin(int(input()))[2:]

rem = len(n) % 2
ans = ["Aoki", "Takahashi"]
for i in range(1, len(n)):
    if i % 2 == rem:
        if int(n[i]) == 0:
            print(ans[i % 2])
            exit(0)
    else:
        if int(n[i]) == 1:
            print(ans[i % 2])
            exit(0)

print(ans[(len(n) - 1) % 2])
