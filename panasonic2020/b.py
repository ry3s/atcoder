h, w = map(int, input().split())

if h % 2 == 0:
    tate = h // 2
    print(tate * w)
    exit(0)
else:
    tate1 = h // 2 + 1
    tate2 = tate1 - 1
    if w % 2 == 0:
        print(tate1 * (w // 2) + tate2 * (w // 2))
        exit(0)
    else:
        yoko1 = w // 2 + 1
        yoko2 = yoko1 - 1
        print(tate1 * yoko1 + tate2 * yoko2)
        exit(0)
