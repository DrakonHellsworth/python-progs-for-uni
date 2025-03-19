#A project to create a graphing calculator
#Author: [Anmol]
#Batch-38
import tkinter as tk                                                 #GUI tool of python
from tkinter import messagebox                                       #For showing pop up dialogs like error messages for wrong input
import numpy as np                                                   # A library for numerical operations and array handling
import matplotlib                                                    #for graphing
matplotlib.use("TkAgg")                                              # this ensures the plots rendered by matplotlib are embedded in the tkinter gui
import matplotlib.pyplot as plt                                      # to provide MATLAB like inteface to createand customize figures and plots
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg      # to embedd plots in tkinter gui
from mpl_toolkits.mplot3d import Axes3D                              # for 3D plots

#Main Window
root=tk.Tk()                                                         #This makes it so that the variable root refers to the main window
root.title("Graphing Calculator")                                    #This sets the title opf the window as "Graphing Claculator"
root.geometry("400x450")                                             #This sets the size of the window

#the frame and buttons
frame=tk.Frame(root)                                                 #This creates a frame widget inside root for labels buttons and input output etc.
frame.place(relx=0.5,rely=0.5,anchor="center")                       #This places the frame at the center of the window

#input and output labels
L=tk.Label(frame,text="Enter the equation to be graphed:",font=("Arial",14))#This creates a label with font and size 
L.pack(pady=10)                                                      #This packs the label

#input box
E=tk.Entry(frame,width=50)                                           #This creates an input box
E.pack(pady=5)                                                       #This packs the input box on the left of the frame

C=None                                                               #This is a Global variable to store the embedded plot

def plot(event=None):                                                #This is a function to plot the graph
    global C                                                         #This makes it so that any modification affects the global variable C
    st=E.get()                                                       #This gets the input from the input box and stores it in str
    if not st:                                                       # if str is empty as no equation is entered
        messagebox.showerror("Error","Please enter an equation")     #This shows an error message
        return                                                       #This returns to the input box 
    try:                                                             # this function tries to execute the following code and if any error occurs it jumps to the except block
        x=np.linspace(-10,10,500)                                    #This creates an array of 500 values between -10 and 10
        y=np.linspace(-10,10,500)                                    #This creates an array of 500 values between -10 and 10
        x,y=np.meshgrid(x,y)                                         #This takes 1D arrays and creates 2D arrays X and Y by creating every possible pair of elements from the 1D arrays
        allowed={"np":np,"x":x,"y":y}                                #This is a dictionary of allowed functions
        z=eval(st,allowed)
    except Exception as e:                                           #this block is executed if any error occurs in the try block
        messagebox.showerror("Error","Invalid equation")             #This shows an error message
        return                                                       #This returns to the input box
    fig=plt.figure(figsize=(6,6),dpi=100)                            #This creates a figure with size 6x6, resolution 100 and stores it in fig(dots per inch)
    ax=fig.add_subplot(111,projection='3d')                          #This creates a 3D plot and stores it in ax(111=1row,1column,1plot)
    s=ax.plot_surface(x,y,z,cmap="coolwarm")                         #This plots the surface of the 3D plot and stores it in s,cmap is used to give colors to the plot
    fig.colorbar(s,ax=ax,shrink=0.5,aspect=5)                        #adds a colorbar to the graph with a scale of 0.5 and thickness of 5
    ax.set_xlabel("x")                                               #This sets the label of the x axis as x
    ax.set_ylabel("y")                                               #This sets the label of the y axis as y
    ax.set_zlabel("z")                                               #This sets the label of the z axis as z
    if C:                                                            # if C is not None
        C.get_tk_widget().destroy()                                  #This destroys the previous plot
    C=FigureCanvasTkAgg(fig,master=root)                             #This creates a new plot and stores it in C
    C.draw()                                                         #This draws the plot
    C.get_tk_widget().pack(side=tk.TOP,fill=tk.BOTH,expand=True)     #This packs the plot in the window from top and allowing it to fill both vertically and horizontally and also allowing it to take any free space
    if hasattr(plot,'label'):                                        #This checks if the function has a label attribute
        plot.label.destroy()                                         #This destroys the previous plot
    plot.label=tk.Label(root,text=f"3D plot of-'{st}'",font=("Arial",13),anchor="w",justify="left")#This creates a label and stores it in plot.label with font Arial and size 13
    plot.label.pack(side=tk.RIGHT,padx=650,pady=10)                  #This packs the label on the right of the plot with padding
    E.bind("<Return>",plot)                                           #This binds the enter key to the plot function
    
B=tk.Button(frame,text="Plot",command=plot)                          #This creates a button named plot and calls the function plot when clicked
B.pack(side=tk.RIGHT,padx=500)                                       #This packs the button on the right of the frame
        
#main loop
root.mainloop()

"""
    The code creates a graphing calculator using tkinter for the GUI, allowing users to input equations
    and visualize 3D plots of the equations entered.
    :return: The code provided is a Python script for a graphing calculator application using tkinter
    for the GUI, numpy for numerical operations, and matplotlib for plotting graphs. When the user
    enters an equation in the input box and clicks the "Plot" button, the code evaluates the equation
    and generates a 3D plot of the function.
"""