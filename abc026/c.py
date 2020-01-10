import sys

sys.setrecursionlimit(100000)
n = int(input())
bs = [(i + 1, int(input()) - 1) for i in range(n - 1)]


def calc(i):
    flag = False
    for j, b in bs:
        if b == i:
            flag = True

    if not flag:
        return 1

    maxi = 0
    mini = 1000000
    for j, b in bs:
        if b == i:
            maxi = max(maxi, calc(j))
            mini = min(mini, calc(j))

    return maxi + mini + 1


print(calc(0))
