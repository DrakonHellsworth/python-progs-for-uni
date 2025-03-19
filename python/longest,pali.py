#find the longest palindrome substring in a user given string
def longpali(s):
    n=len(s)
    if n<2:
        return s
    dp=[]
    for i in range(n):
        dp.append([False]*n)
    for i in range(n):
        dp[i][i]=True
    start=0
    long=1
    for i in range(n-1):
        if s[i]==s[i+1]:
            dp[i][i+1]=True
            start=i
            long=2
    for L in range(3,n+1):
        for i in range(0,n-L+1):
            j=i+L-1
            if dp[i+1][j-1] and s[i]==s[j]:
                dp[i][j]=True
                start=i
                long=L
    return s[start:start+long]
s=input("Enter a string: ")
print("Longest palindrome substring:", longpali(s))
