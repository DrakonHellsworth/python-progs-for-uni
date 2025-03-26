#Write a recursive function to print Fibonacci series upto n terms. 
def fibo(n):
    if n<=1:
        return n
    else:
        return fibo(n-1)+fibo(n-2)
n=int(input("Enter the number of terms: "))
for i in range(n):
    print(fibo(i))
