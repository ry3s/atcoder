s = input()
k = int(input())

n = len(s)
st = set()
for i in range(n - k + 1):
    substr = s[i:i + k]
    st.add(substr)

print(len(st))
