a, b, c, d = map(int, input().split())

takahasi = a
aoki = c
flag = True
while True:
    if takahasi <= 0:
        print("No")
        break
    elif aoki <= 0:
        print("Yes")
        break
    elif flag:
        aoki -= b
        flag = False
    else:
        takahasi -= d
        flag = True
