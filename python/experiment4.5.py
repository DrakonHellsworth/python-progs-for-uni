n=int(input("Enter a number:"))
t=n
r=0
while(n>0):
    b=n%10
    r=r*10+b
    n=n//10
if(t==r):
    print("Number is palindrome")
else:
    print("Number is not palindrome")