import numpy as np

n, k = map(int, input().split())
ps = np.array(list(map(int, input().split())))

acc = np.zeros(n + 1, np.int32)
acc[1:] = ps.cumsum()

length_k_sums = acc[k:] - acc[:-k]
print(length_k_sums.max() / 2)
