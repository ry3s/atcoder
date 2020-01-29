n = int(input())
arr = [int(input()) for _ in range(n)]

count = 0
st = set()
for a in arr:
    if a in st:
        count += 1
    else:
        st.add(a)

print(count)
