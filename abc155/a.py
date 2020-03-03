a, b, c = map(int, input().split())

if a == b and b == c and c == a:
    print("No")
elif a != b and b != c and c != a:
    print("No")
else:
    print("Yes")
