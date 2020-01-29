from collections import deque

n = int(input())
s = input()

dq = deque()
dq.append("b")
i = 1
while True:
    if len(dq) > len(s):
        print(-1)
        exit(0)

    if dq == deque(s):
        print(i - 1)
        exit(0)

    if i % 3 == 1:
        dq.appendleft('a')
        dq.append('c')
    elif i % 3 == 2:
        dq.appendleft('c')
        dq.append('a')
    else:
        dq.appendleft('b')
        dq.append('b')

    i += 1
