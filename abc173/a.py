import math

n = int(input())
m = math.ceil(n / 1000)
print(m * 1000 - n)
