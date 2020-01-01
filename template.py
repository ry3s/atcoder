# input
s = input()  # s = 'abcde'
s = list(input())  # s = ['a', 'b', 'c', 'd', 'e']
a = int(input())  # a = 5
x, y = map(int, input().split())  # x = 1, y = 2
lst = input().split()  # lst = ['1','2','3',...,'n']
lst = list(map(int, input().split()))  # lst = [1,2,3,4,5,...,n]
li = input().split('T')  # lst = ['FFF', 'F', '', 'FF']

n = int(input())
string_list = [input() for i in range(n)]

# output
a = 3.14
print("{:.6f}".format(a))

print("python".ljust(15, '-'))  # 左詰め
# python---------
print("python".center(15, '-'))  # 中央寄せ
# -----python----
print("python".rjust(15, '-'))  # 右詰め
# ---------python
print(str(29).rjust(10, '0'))  # 10桁ゼロ埋め
# 0000000029

# binary search
import bisect
listA = [1, 2, 5, 2, 4, 6, 7, 8, 6, 56, 3, 56, 76, 34, 32, 2, 6, 0, 32, 6, 0]
listA.sort()
zeroindex = bisect.bisect_right(listA, 0)  # ソートされたリスト内で0の場所を探し、右側Indexを返す
clearlistA = listA[zeroindex:]  # 0以下が存在しないリストを得る


# set
set_x = set([1, 2, 3])
set_y = set([2, 3, 4])
union = set_x | set_y
intersection = set_x & set_y
