#A project to create a graphing calculator
#Author: [Anmol]
#Batch-38
import tkinter as tk
from tkinter import *
from tkinter import messagebox                              # for showing error dialogs
import numpy as np                                          #for numerical operations such as creating array of points betwwen two numbers
import matplotlib                 
matplotlib.use("TkAgg")                                     # to ensur tkagg backend is use for gui integration with tkinter
from matplotlib.pyplot as plt                               # for graphing
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg # to embedd plots in tkinter gui

#for application widow creation
root=tk.Tk()                                                #intializes the window
root.title("Graphing Calculator")                           #The windows title

#the frame and buttons
in_frame=tk.Frame(root)                                     #creates a frame/container to hold the widgets
in_frame.pack(side=tk.TOP,fill=tk.x, padx=10,pady=10)       #Adds rame to the window , pos at the top of the window with some padding

#Labels of instructions
L=tk.Label(in_frame,text="Enter the equation to be graphed:")
L.pack(side=tk.LEFT)

#the entry field (where to type)
E=tk.Entry(in_frame,width=40)                                #the entry field
E.pack(side=tk.LEFT,padx=10)

#Create a Button
B=tk.Button(in_frame,text="Graph",command=lambda:P())        #the button
B.pack(side=tk.LEFT,padx=10)

def P():                                                     #this function gets the user input and make the x values from it
    global Canvas
    str=E.get()                                              #gets the user input as string
    if not str:                                              #if the user input is empty
        messagebox.showerror("Error","Please enter an equation") #show error message
        return
    try:
        x=np.linspace(-10,10,500)                            #create an array of 500 points between -10 and 10


