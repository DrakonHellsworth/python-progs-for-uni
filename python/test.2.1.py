#Write a NumPy program to create a 4×4 matrix filled with values from 0 to 15 and reshape it into a 2D array
import numpy as np
a=np.array(range(16))
a=a.reshape(4,4)
print(a)