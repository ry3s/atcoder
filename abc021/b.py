n = int(input())
a, b = map(int, input().split())
k = int(input())
plist = list(map(int, input().split()))

visited = set()
for p in plist:
    if p in visited or p == a or p == b:
        print("NO")
        exit(0)
    visited.add(p)

print("YES")
