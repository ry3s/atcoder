n, m = map(int, input().split())

short_hand = (n % 12) * 30.0 + m * (30.0 / 60.0)
long_hand = m * 6.0

x = 360.0 - abs(short_hand - long_hand)
y =  abs(short_hand - long_hand)
if x < y:
    print("{:.5}".format(x))
else:
    print("{:.5}".format(y))
