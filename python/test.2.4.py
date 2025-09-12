#Create a NumPy array of 10 random integers between 1 and 100. Convert it into a Pandas Series and calculate the mean, standard deviation, and sort the values in descending order. 
import numpy as np
import pandas as pd
a=np.random.randint(1,101,10)
s=pd.Series(a)
print("Non-sorted array:")
print(s)
print("Mean of the array:",s.mean())
print("Standard Deviation of the array:",s.std())
print("Sorted values in descending order:")
print(s.sort_values(ascending=False))  