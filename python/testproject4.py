import tkinter as tk
from tkinter import messagebox
import numpy as np
import sympy as sp
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

def plot_graph():
    eq = entry_eq.get().strip()  # Get equation
    vars_input = entry_vars.get().strip().split(",")  # Get variables & constants

    variables = {}  # Dictionary for variables
    constants = {}  # Dictionary for constants

    for item in vars_input:
        item = item.strip()
        if "=" in item:  # Check if it's a constant (e.g., a=1)
            key, value = item.split("=")
            constants[key.strip()] = float(value.strip())  # Store as a number
        else:
            variables[item] = sp.Symbol(item)  # Store as a variable

    if not eq:
        messagebox.showerror("Error", "Enter a valid equation.")
        return

    try:
        # Replace constants inside the equation
        for const, val in constants.items():
            eq = eq.replace(const, str(val))

        symbols = {**variables}  # Merge variables into symbols dictionary

        # 📌 Handle missing `=` by assuming `F(x, y, z) = 0`
        if "=" in eq:
            lhs, rhs = eq.split("=")
            expr = sp.sympify(lhs.strip(), locals=symbols) - sp.sympify(rhs.strip(), locals=symbols)
        else:
            expr = sp.sympify(eq, locals=symbols)  # Assume `F(x, y, z) = 0`

        # 📌 ✅ Case 1: If only constants exist (e.g., "a = 5")
        if len(variables) == 0:
            plt.axhline(float(expr), color="blue", linestyle="--", label=f"Constant: {expr}")
            plt.xlabel("x")
            plt.ylabel("y")
            plt.legend()
            plt.title("Constant Line")
            plt.grid()
            plt.show()
            return

        # 📌 ✅ Case 2: If one variable exists (2D Graph)
        if len(variables) == 1:
            x = np.linspace(-10, 10, 400)
            y = [expr.subs(symbols[list(variables.keys())[0]], val).evalf() for val in x]

            plt.figure(figsize=(6, 4))
            plt.plot(x, y, label=f"{eq}")
            plt.axhline(0, color="black", linewidth=0.5)
            plt.axvline(0, color="black", linewidth=0.5)
            plt.grid(True)
            plt.legend()
            plt.title("2D Graph")
            plt.show()

        # 📌 ✅ Case 3: If two variables exist (3D Surface Plot)
        elif len(variables) == 2:
            x_vals = np.linspace(-5, 5, 30)
            y_vals = np.linspace(-5, 5, 30)
            X, Y = np.meshgrid(x_vals, y_vals)
            Z = np.array([[expr.subs({symbols[list(variables.keys())[0]]: x, symbols[list(variables.keys())[1]]: y}).evalf()
            blackjack.for x in x_vals] for y in y_vals])

            fig = plt.figure(figsize=(7, 6))
            ax = fig.add_subplot(111, projection='3d')
            ax.plot_surface(X, Y, Z, cmap='coolwarm')

            ax.set_xlabel(list(variables.keys())[0])
            ax.set_ylabel(list(variables.keys())[1])
            ax.set_zlabel("z")
            ax.set_title("3D Surface Plot")
            plt.show()

        # 📌 ✅ Case 4: If three variables exist (Implicit 3D Plot)
        elif len(variables) == 3:
            x_vals = np.linspace(-3, 3, 20)
            y_vals = np.linspace(-3, 3, 20)
            z_vals = np.linspace(-3, 3, 20)

            X, Y, Z = np.meshgrid(x_vals, y_vals, z_vals)
            F = np.vectorize(lambda x, y, z: float(expr.subs({symbols['x']: x, symbols['y']: y, symbols['z']: z}).evalf()))
            values = F(X, Y, Z)

            fig = plt.figure(figsize=(7, 6))
            ax = fig.add_subplot(111, projection='3d')
            ax.contour3D(X, Y, Z, values, levels=10, cmap=cm.coolwarm)

            ax.set_xlabel("x")
            ax.set_ylabel("y")
            ax.set_zlabel("z")
            ax.set_title("3D Implicit Contour Plot")
            plt.show()

        else:
            messagebox.showerror("Error", "Only supports 1, 2, or 3 independent variables.")
    except Exception as e:
        messagebox.showerror("Error", "Invalid equation or variables.")

# Tkinter UI
root = tk.Tk()
root.title("Advanced Graphing Calculator")
root.geometry("400x250")

tk.Label(root, text="Equation (use variables like x, y, z):").pack()
entry_eq = tk.Entry(root, width=40)
entry_eq.pack()

tk.Label(root, text="Variables (comma-separated, e.g., x,y or a=1,b=2,x):").pack()
entry_vars = tk.Entry(root, width=40)
entry_vars.pack()

btn_plot = tk.Button(root, text="Plot Graph", command=plot_graph)
btn_plot.pack(pady=10)

root.mainloop()
