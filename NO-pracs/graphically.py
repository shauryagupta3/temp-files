import matplotlib.pyplot as plt
import numpy as np

def f(x):
    return -10 * np.cos(np.pi * x - 2.2) + (x + 1.5) * x

x = np.linspace(-2, 5, 400)

y = f(x)

optimal_x_graphical = x[np.argmin(y)]
optimal_value_graphical = np.min(y)

plt.figure(figsize=(8, 6))
plt.plot(x, y, label='f(x) = -10Cos(πx - 2.2) + (x + 1.5)x')
plt.scatter(optimal_x_graphical, optimal_value_graphical, color='red', label='Global Minimum')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.grid(True)
plt.title('Graphical Solution')
plt.show()

print("Global Optimal Solution (Graphical): x =", optimal_x_graphical, ", f(x) =", optimal_value_graphical)
