import matplotlib.pyplot as plt
import numpy as np

def constraint1(x):
    return (12 - 2 * x) / 3

def constraint2(x):
    return (20 - 5 * x) / 4

def objective_function(x):
    return 3 * x

x = np.linspace(0, 10, 400)

plt.figure(figsize=(8, 6))
plt.plot(x, constraint1(x), label='2x + 3y ≤ 12')
plt.plot(x, constraint2(x), label='5x + 4y ≤ 20')

x_values = np.array([0, 4, 8])
y_values = constraint1(x_values)
plt.fill_between(x_values, y_values, color='gray', alpha=0.5, label='Feasible Region')

plt.plot(x, objective_function(x), label='Objective Function: 3x', linestyle='--')

optimal_x = 4
optimal_y = constraint1(optimal_x)
plt.scatter(optimal_x, optimal_y, color='red', zorder=5)
plt.annotate('Optimal\nSolution\n(4, 4)', xy=(optimal_x, optimal_y), xytext=(4.5, 4.5),
             arrowprops=dict(facecolor='black', shrink=0.05))

plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid(True)
plt.title('Graphical Solution of Linear Programming Problem')
plt.xlim(0, 10)
plt.ylim(0, 10)
plt.show()
