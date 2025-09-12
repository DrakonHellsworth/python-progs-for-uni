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
root.configure(bg="#1e1e1e")                                         #This sets the background color

#the frame and buttons
frame=tk.Frame(root,bg="#1e1e1e")                                    #This creates a frame widget inside root for labels buttons and input output etc.
frame.place(relx=0.5,rely=0.5,anchor="center")                       #This places the frame at the center of the window

#input and output labels
L=tk.Label(frame,text="Enter the equation to be graphed:",font=("Arial",14),bg="#1e1e1e",fg="white")#This creates a label with font and size 
L.pack(pady=10)                                                      #This packs the label

#input box
E=tk.Entry(frame,width=50,bg="#252256",fg="white",insertbackground="white",font=("Arial",12))                                           #This creates an input box
E.pack(pady=5)                                                       #This packs the input box on the left of the frame
E.focus_set()                                                        #This sets the focus on the input 
E.bind("<Return>",lambda event:plot())                               #This binds the enter key to the plot function

def close():
    root.destroy()                                                   #This function closes the main window

close=tk.Button(frame,text="Close",command=close,font=("Arial",13,"bold"),bg="#252256",fg="white")#This creates a button named close and calls the function close when clicked
close.pack(side=tk.BOTTOM,pady=10)                          #This packs the button on the bottom of the frame

graph=None                                                           #This is a Global variable to store the 3D plot
allow={                                                              #This is a dictionary of allowed functions
    'sin':np.sin,
    'cos':np.cos,
    'tan':np.tan,
    'sqrt':np.sqrt,
    'log':np.log,
    'exp':np.exp,
    'pi':np.pi,
    'e':np.e,
}

def plot(event=None):                                                #This is a function to plot the graph
    global graph                                                     #This makes it so that any modification affects the global variable C
    st=E.get()                                                       #This gets the input from the input box and stores it in str
    if not st:                                                       # if str is empty as no equation is entered
        messagebox.showerror("Error","Please enter an equation")     #This shows an error message
        return                                                       #This returns to the input box 
    
    try:                                                             # this function tries to execute the following code and if any error occurs it jumps to the except block
        
        st=st.replace('^','**')                                      #This replaces ^ with **
        x=np.linspace(-10,10,500)                                    #This creates an array of 500 values between -10 and 10
        y=np.linspace(-10,10,500)                                    #This creates an array of 500 values between -10 and 10
        x,y=np.meshgrid(x,y)                                         #This takes 1D arrays and creates 2D arrays X and Y by creating every possible pair of elements from the 1D arrays
        
        allowed={**allow,"x":x,"y":y}                                #This is a dictionary of allowed functions
        z=eval(st,allowed)                                           #This evaluates the string and stores it in z
        
    except Exception as e:                                           #this block is executed if any error occurs in the try block
        messagebox.showerror("Error",f"Invalid equation:\n{e}")      #This shows an error message
        return                                                       #This returns to the input box
    
    if graph:                                                        # if graph is not None
        graph.get_tk_widget().destroy()                              #This destroys the previous plot
    
    graph=tk.Toplevel(root)                                          #This creates a new window and stores it in graph
    graph.title("Graph")                                             #This sets the title of the window as "Graph"
    graph.geometry("800x600")                                        #This sets the size of the window
    graph.configure(bg="#1e1e1e")                                    #This sets the background color
    
    fig=plt.figure(figsize=(6,6),dpi=100)                            #This creates a figure with size 6x6, resolution 100 and stores it in fig(dots per inch)
    ax=fig.add_subplot(111,projection='3d')                          #This creates a 3D plot and stores it in ax(111=1row,1column,1plot)
    s=ax.plot_surface(x,y,z,cmap="coolwarm")                         #This plots the surface of the 3D plot and stores it in s,cmap is used to give colors to the plot
    
    cbar=fig.colorbar(s,ax=ax,shrink=0.5,aspect=5)                   #adds a colorbar to the graph with a scale of 0.5 and thickness of 5
    cbar.ax.yaxis.set_tick_params(color="white")
    cbar.outline.set_edgecolor("white")
    plt.setp(plt.getp(cbar.ax.axes, 'yticklabels'), color="white")
    
    label=tk.Frame(graph)                                            #This creates a frame widget inside graph and stores it in label
    label.pack(pady=5)                                               #This packs the frame on the top of the graph with padding
    
    ax.set_xlabel("x")                                               #This sets the label of the x axis as x
    ax.set_ylabel("y")                                               #This sets the label of the y axis as y
    ax.set_zlabel("z")                                               #This sets the label of the z axis as z
    
    C=FigureCanvasTkAgg(fig,master=graph)                            #This creates a new plot and stores it in C
    C.draw()                                                         #This draws the plot
    C.get_tk_widget().pack(side=tk.TOP,fill=tk.BOTH,expand=True)     #This packs the plot in the window from top and allowing it to fill both vertically and horizontally and also allowing it to take any free space
    
    plot.label=tk.Label(label,text=f"3D plot of equation:'{st}'",font=("Arial",13,"bold"))#This creates a label and stores it in plot.label with font Arial and size 13
    plot.label.pack(side="left",padx=10)                             #This packs the label on the right of the plot with padding
    
    close=tk.Button(label,text="Close",command=graph.destroy,font=("Arial",13,"bold"))#This creates a button named close and calls the function graph.destroy when clicked
    close.pack(side="right",padx=10)                                 #This packs the button
    
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