import functools
import operator
s = list(input())

s.append('+')
stack = []
cnt = 0
for ch in s:
    if ch.isdigit():
        stack.append(int(ch))

    elif ch == '+':
        prod = functools.reduce(operator.mul, stack)
        if prod != 0:
            cnt += 1
        stack = []

print(cnt)
