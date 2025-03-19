#take input in a 2d matrix and flip it
def flip_matrix(matrix):
    flip_rows=[row[::-1] for row in matrix]
    flipped=flip_rows[::-1]
    return flipped
rows=int(input("Enter number of rows: "))
cols=int(input("Enter number of columns: "))
matrix=[]
print("Enter the matrix row by row:")
for i in range(rows):
    row=[]
    for j in range(cols):
        row.append(int(input(f"Element [{i+1}][{j+1}]: ")))
    matrix.append(row)
print("Original matrix:")
for row in matrix:
    print(" ".join(map(str, row)))
flipped_matrix=flip_matrix(matrix)
print("Flipped matrix:")
for row in flipped_matrix:
    print(" ".join(map(str,row)))