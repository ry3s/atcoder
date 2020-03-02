n = int(input())
a = map(int, input().split())

st = set()
for x in a:
    if x in st:
        print("NO")
        exit(0)
    else:
        st.add(x)

print("YES")
