n = list(input())

if all([digit == n[0] for digit in n]):
    print("SAME")
else:
    print("DIFFERENT")
