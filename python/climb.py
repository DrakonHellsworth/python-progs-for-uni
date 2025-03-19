#take number of rungs as input and print the number of ways to reach the top the maximum  number of steps is 3 (for 4 it would be 7 ways [1,1,1,1],[1,1,2][1,2,1]....etc)
def count(n):
    if n<0:
        return 0
    if n==0:
        return 1
    return count(n-1)+count(n-2)+count(n-3)
n=int(input("Enter number of rungs: "))
print(f"Number of ways to reach the top: {count(n)}")
