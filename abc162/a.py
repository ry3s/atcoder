n = int(input())

x = n % 10
y = (n // 10) % 10
z = n // 100
if x == 7 or y == 7 or z == 7:
    print("Yes")
else:
    print("No")
