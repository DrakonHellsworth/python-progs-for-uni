#Write a Pandas program to find and replace the missing values in a given DataFrame which do not have any valuable information. 
import pandas as pd
import numpy as np
d = {'X': [78, 85, np.nan, 80, 86], 
    'Y': [84, np.nan, 89, 83, 86], 
    'Z': [86, 97, 96, np.nan, 83]
    }
df = pd.DataFrame(d)
print("Original DataFrame with missing values:")
print(df)
df = df.fillna(0)
print("\nDataFrame after replacing missing values with 0:")
print(df)
