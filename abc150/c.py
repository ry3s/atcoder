import itertools

n = int(input())
ps = tuple(map(int, input().split()))
qs = tuple(map(int, input().split()))

perm = []
for i in range(1, n + 1):
    perm.append(i)

for i, x in enumerate(itertools.permutations(perm)):
    if x == ps:
        a = i
    if x == qs:
        b = i

print(abs(a - b))
