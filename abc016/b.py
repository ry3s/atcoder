a, b, c = map(int, input().split())
add = a + b
sub = a - b
if add == c and sub == c:
    print("?")
elif add == c and sub != c:
    print("+")
elif add != c and sub == c:
    print("-")
else:
    print("!")
