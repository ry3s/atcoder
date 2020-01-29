n = int(input())

ans = n // 2;
res = n % 2;

print(ans + res)
if res == 1:
    print(1)

for i in range(ans):
    print(2)
