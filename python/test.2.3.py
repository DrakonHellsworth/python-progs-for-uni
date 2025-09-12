#Write a Python script to plot a line graph for the following data: x = [1,2,3,4,5] y = [10, 20, 25, 30, 40] Label the axes, add a title, and display the grid. 
import matplotlib.pyplot as plt
import numpy as np
x=np.array([1,2,3,4,5])
y=np.array([10,20,25,30,40])
plt.plot(x,y)
plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.title("Graph of a line with given points")
plt.grid(True)
plt.show()
