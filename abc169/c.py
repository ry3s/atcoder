import decimal
a, b = input().split()
a = decimal.Decimal(a)
b = decimal.Decimal(b)
print(int(a * b))
