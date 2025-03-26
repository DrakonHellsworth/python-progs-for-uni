#Write a Python function to print 1 to n using recursion. (Note: Do not use loop)
def print1(n):
    if n==1:
        print(1)
    else:
        print1(n-1)
        print(n)
n=int(input("Enter a positive integer: "))
print1(n)