import math


def gcd(m, n):
    x = max(m, n)
    y = min(m, n)
    if x % y == 0:
        return y
    else:
        while x % y != 0:
            z = x % y
            x = y
            y = z
        else:
            return z


a = int(input())
b = int(input())
n = int(input())

lcm = (a * b) // gcd(a, b)
x = math.ceil(n / lcm)

print(x * lcm)
