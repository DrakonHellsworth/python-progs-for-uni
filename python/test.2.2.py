#Create a Pandas DataFrame from a dictionary with columns: Name, Age, and Score. Display the first 2 rows and add a new column called 'Grade' with some values
import pandas as pd
data={'Name':['Augy','Rahul','Kapil'],'Age':[21,20,19],'Score': [95, 92, 93]}
df=pd.DataFrame(data,columns=['Name','Age','Score'],index=[1,2,3])
print(df.head(2))
df['Grade']=['A','B','C']
print(df)