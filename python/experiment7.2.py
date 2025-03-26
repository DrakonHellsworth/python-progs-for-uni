#Write a Python function that takes a positive integer and returns the sum of the cube of all the positive integers smaller than the specified number.
def cubesum(n):
    sum=0
    for i in range(1,n):
        sum+=i**3
    return sum
n=int(input("Enter a positive integer: "))
print(f"The sum of cube of all the positive integers smaller than {n} is {cubesum(n)}")