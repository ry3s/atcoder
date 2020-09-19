s = input()
n = len(s)
if s[n - 1] == "s":
    s += "es"
    print(s)
else:
    s += "s"
    print(s)
