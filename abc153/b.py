h, n = map(int, input().split())
arr = list(map(int, input().split()))

sm = sum(arr)
if sm >= h:
    print("Yes")
else:
    print("No")
