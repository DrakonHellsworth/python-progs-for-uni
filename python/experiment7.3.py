#Write a Python function to print 1 to n using recursion. (Note: Do not use loop)
def print_to_n(n):
    if n==0:
        return
    print_to_n(n-1)
    print(n)
n=int(input("Enter a positive integer: "))
print_to_n(n)