n, m, k = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

i = 0
j = 0
arr = []
while True:
    print(i, j, arr)
    if i < n and j < m:
        if A[i] < B[j]:
            arr.append(A[i])
            i += 1
        else:
            arr.append(B[j])
            j += 1
    elif i >= n:
        arr.extend(B[j:])
        break
    else:
        arr.extend(A[i:])
        break

print(arr)
t = 0
i = 0
cnt = 0
while True:
    if i < n + m and t + arr[i] <= k:
        t += arr[i]
        i += 1
    else:
        break
print(i)
