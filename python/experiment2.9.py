n=int(input("Enter a number:"))
if(n<0):
    print("Number cannot be negative")
else:
    s=(n*(n+1))/2
    print("Sum of first",n,"natural numbers:",s)
