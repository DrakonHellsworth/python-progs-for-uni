#Write a recursive function to print Fibonacci series upto n terms. 
def printFibonacci(n):
    if n <= 1:
        return n
    else:   
        return(printFibonacci(n-1) + printFibonacci(n-2))
    #Test the function
n=int(input("Enter a positive integer: "))
if n <= 0:
    print("Please enter a positive integer")
else:
    print(printFibonacci(n))