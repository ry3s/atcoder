import math
a, b, h, m = map(int, input().split())

time = h * 60 + m
hh = time * (360 / (12 * 60))
mm = time * (360 / 60)
deg = min(abs(hh - mm), 360 - abs(hh - mm))

ans = a * a + b * b - 2 * a * b * math.cos(math.radians(deg))

print(math.sqrt(ans))
