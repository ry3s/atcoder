n = int(input())

m = n % 10
if m == 2 or m == 4 or m == 5 or m == 7 or m == 9:
    print("hon")
elif m == 0 or m == 1 or m == 6 or m == 8:
    print("pon")
else:
    print("bon")
