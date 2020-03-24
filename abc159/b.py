
def ispalindrome(s):
        return True if s == s[::-1] else False

s = input()
n = len(s)
if ispalindrome(s) and ispalindrome(s[:(n - 1) // 2]) and ispalindrome(s[(n + 3)//2 -1:n]) :
    print("Yes")
else:
    print("No")
