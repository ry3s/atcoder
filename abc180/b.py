n = int(input())
xs = list(map(int, input().split()))

print(sum(map(abs, xs)))
print(sum(map(lambda x: x ** 2, xs)) ** 0.5)
print(max(map(abs, xs)))
