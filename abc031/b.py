l, h = map(int, input().split())
n = int(input())
a = [int(input()) for _ in range(n)]

for x in a:
    if x > h:
        print(-1)
    elif x < l:
        print(l - x)
    else:
        print(0)
