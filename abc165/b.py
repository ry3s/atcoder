import math
x = int(input())
cnt = 0
sm = 100
while True:
    sm = int(sm * 1.01)
    cnt += 1
    if sm >= x:
        print(cnt)
        exit(0)
