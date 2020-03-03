n = int(input())
a = list(map(int, input().split()))

ans = True
for x in a:
    if not x % 2 == 0 or (x % 3 == 0 or x % 5 == 0):
        pass
    else:
        ans = False

if ans:
    print("APPROVED")
else:
    print("DENIED")
