#Perform Matrix multiplication of any 2 n*n matrices
"""def matmul(a,b):
    n=len(a)  
    result=[[0 for _ in range(n)] for _ in range(n)]  
    for i in range(n):
        for j in range(n):
            for k in range(n):  
                result[i][j]+=a[i][k]*b[k][j]  
    return result
a=[[1,2,3],[4,5,6],[7,8,9]]
b=[[9,8,7],[6,5,4],[3,2,1]]
result=matmul(a,b)
print(f"the result is:")
for i in result:
    print(i)"""
import numpy as np
n=int(input("Enter the size of the matrix: "))
a=np.zeros((n,n))
b=np.zeros((n,n))
print("Enter the elements of 1st matrix:")
for i in range(n):
    for j in range(n):
        a[i][j]=int(input())
print("Enter the elements of 2nd matrix:")
for i in range(n):
    for j in range(n):
        b[i][j]=int(input())
result=np.matmul(a,b)
print("The result is:")
print(result)