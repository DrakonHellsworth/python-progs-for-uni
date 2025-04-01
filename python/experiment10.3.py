#Perform Matrix multiplication of any 2 n*n matrices
def matrix_multiplication(A, B):
    n = len(A)  
    result = [[0 for _ in range(n)] for _ in range(n)]  
    for i in range(n):
        for j in range(n):
            for k in range(n):  
                result[i][j] += A[i][k] * B[k][j]  
    return result
#Test the function with 2 3x3 matrices
A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
B = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]
result = matrix_multiplication(A, B)