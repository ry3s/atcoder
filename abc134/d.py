import sys

sys.setrecursionlimit(10**9)

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
put = []

for i in reversed(range(N)):
    if A[i]:
        put.append(i + 1)

        tmp = 1
        n = i + 1
        while tmp * tmp <= n:
            if n % tmp == 0:
                A[tmp - 1] ^= 1
                if tmp != n // tmp:
                    A[n // tmp - 1] ^= 1
            tmp += 1

if len(put) > 0:
    print(len(put))
    print(*put)
else:
    print(0)
