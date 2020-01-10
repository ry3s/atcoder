n = int(input())

value = 1
turn = 0
while value <= n:
    if turn == 0:
        value = value * 2 + 1
        turn = 1
    else:
        value = value * 2
        turn = 0

if turn == 0:
    print("Takahashi")
else:
    print("Aoki")
