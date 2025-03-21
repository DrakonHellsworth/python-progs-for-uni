# A project to create a graphing calculator
# Author: [Anmol]
# Batch-38

import tkinter as tk
from tkinter import messagebox
import numpy as np
import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from mpl_toolkits.mplot3d import Axes3D

# Main Window
root = tk.Tk()
root.title("Graphing Calculator")
root.geometry("400x450")

# Frame at center of the window
frame = tk.Frame(root)
frame.place(relx=0.5, rely=0.5, anchor="center")

# Input label
L = tk.Label(frame, text="Enter the equation to be graphed:", font=("Arial", 14))
L.pack(pady=10)

# Input box
E = tk.Entry(frame, width=50)
E.pack(pady=5)
E.focus_set()

# Allowed math functions (without np.)
allowed = {
    'sin': np.sin,
    'cos': np.cos,
    'tan': np.tan,
    'sqrt': np.sqrt,
    'log': np.log,
    'exp': np.exp,
    'pi': np.pi,
    'e': np.e,
    'abs': abs
}

graph = None

def plot(event=None):
    global graph
    
    st = E.get()
    if not st:
        messagebox.showerror("Error", "Please enter an equation")
        return
    
    try:
        st = st.replace('^', '**')  # Replace '^' with '**'
        
        # Create a 2D grid for x and y
        x = np.linspace(-10, 10, 500)
        y = np.linspace(-10, 10, 500)
        x, y = np.meshgrid(x, y)
        
        # Evaluate the equation using allowed functions
        z = eval(st, {"__builtins__": None}, {"x": x, "y": y, **allowed})
    
    except Exception as e:
        messagebox.showerror("Error", f"Invalid equation:\n{e}")
        return
    
    # Close previous graph window if already open
    if graph is not None:
        graph.destroy()
    
    # Create new window for the graph
    graph = tk.Toplevel(root)
    graph.title("Graph")
    graph.geometry("800x600")

    # Create a 3D plot
    fig = plt.figure(figsize=(6,6), dpi=100)
    ax = fig.add_subplot(111, projection='3d')
    s = ax.plot_surface(x, y, z, cmap="coolwarm")
    
    # Add color bar
    cbar = fig.colorbar(s, ax=ax, shrink=0.5, aspect=5)
    
    # Add label below the color bar
    label_frame = tk.Frame(graph)
    label_frame.pack(pady=5)

    plot_label = tk.Label(label_frame, text=f"3D Plot of: '{st}'", font=("Arial", 12))
    plot_label.pack(side="left", padx=10)
    
    # Place the close button next to the color bar
    close_btn = tk.Button(label_frame, text="Close Graph", command=graph.destroy, font=("Arial", 10))
    close_btn.pack(side="right", padx=10)
    
    # Embed plot in the graph window
    canvas = FigureCanvasTkAgg(fig, master=graph)
    canvas.draw()
    canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)

# Bind Enter key to plot function
E.bind("<Return>", plot)

# Plot button directly below the input box
B = tk.Button(frame, text="Plot", command=plot)
B.pack(pady=5)

# Main loop
root.mainloop()
