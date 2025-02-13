import tkinter as tk
from tkinter import messagebox
import numpy as np
import sympy as sp
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
def plot_graph():
    eq = entry_eq.get().strip()
    vars_input = entry_vars.get().strip().split(",")  # Get variables from input
    vars_input = [v.strip() for v in vars_input if v.strip()]  # Remove extra spaces

    if not eq or not vars_input:
        messagebox.showerror("Error", "Please enter an equation and variables.")
        return

    try:
        symbols = {v: sp.Symbol(v) for v in vars_input}
        lhs, rhs = eq.split("=") if "=" in eq else (None, eq)

        # Solve for dependent variable (e.g., y in y = x^2)
        if lhs:
            lhs = lhs.strip()
            rhs = rhs.strip()
            if lhs in symbols:
                expr = sp.solve(sp.Eq(symbols[lhs], sp.sympify(rhs, locals=symbols)), symbols[lhs])[0]
                vars_input.remove(lhs)
            else:
                expr = sp.sympify(eq, locals=symbols)
        else:
            expr = sp.sympify(eq, locals=symbols)

        if len(vars_input) == 1:  # 2D Graph
            x = np.linspace(-10, 10, 400)
            y = [expr.subs(symbols[vars_input[0]], val).evalf() for val in x]

            plt.figure(figsize=(6, 4))
            plt.plot(x, y, label=f"{eq}")
            plt.axhline(0, color="black", linewidth=0.5)
            plt.axvline(0, color="black", linewidth=0.5)
            plt.grid(True)
            plt.legend()
            plt.title("2D Graph")
            plt.show()

        elif len(vars_input) == 2:  # 3D Surface Plot
            x_vals = np.linspace(-5, 5, 30)
            y_vals = np.linspace(-5, 5, 30)
            X, Y = np.meshgrid(x_vals, y_vals)
            Z = np.array([[expr.subs({symbols[vars_input[0]]: x, symbols[vars_input[1]]: y}).evalf()
            for x in x_vals] for y in y_vals])

            fig = plt.figure(figsize=(6, 5))
            ax = fig.add_subplot(111, projection='3d')
            ax.plot_surface(X, Y, Z, cmap='coolwarm')

            ax.set_xlabel(vars_input[0])
            ax.set_ylabel(vars_input[1])
            ax.set_zlabel("f(x, y)")
            ax.set_title("3D Surface Plot")
            plt.show()

        else:
            messagebox.showerror("Error", "Only supports up to 2 independent variables.")
    except Exception as e:
        messagebox.showerror("Error", "Invalid equation or variables.")

# Tkinter UI
root = tk.Tk()
root.title("Advanced Graphing Calculator")
root.geometry("400x250")

tk.Label(root, text="Equation (use variables like x, y):").pack()
entry_eq = tk.Entry(root, width=40)
entry_eq.pack()

tk.Label(root, text="Variables (comma-separated, e.g., x,y):").pack()
entry_vars = tk.Entry(root, width=40)
entry_vars.pack()

btn_plot = tk.Button(root, text="Plot Graph", command=plot_graph)
btn_plot.pack(pady=10)

root.mainloop()
