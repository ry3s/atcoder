n = int(input())
ps = list(map(int, input().split()))

mini = 0
st = set()
for i in range(n):
    st.add(ps[i])
    if ps[i] == mini:
        x = mini
        while True:
            if x not in st:
                mini = x
                break
            else:
                x += 1
    print(mini)
