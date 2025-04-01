#Create numpy array of (3,3) dimension. Now find sum of all rows & columns individually. Also find 2nd maximum element in the array. 
import numpy as np
a=np.array([[1,2,3],[4,5,6],[7,8,9]])
print("Sum of rows:",a.sum(axis=1))
print("Sum of columns:",a.sum(axis=0))
print("2nd maximum element:",np.partition(a.flatten(),-2)[-2])