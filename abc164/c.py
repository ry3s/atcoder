n = int(input())
arr = [input() for _ in range(n)]

st = set()
for x in arr:
    st.add(x)

print(len(st))
