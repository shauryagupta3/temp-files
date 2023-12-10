import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import minimize_scalar

def objective_function(vars):
    x, y = vars
    return x**2 + 4*y**2 + 4*x + 8*y + 9

def gradient(vars):
    x, y = vars
    df_dx = 2*x + 4
    df_dy = 8*y + 8
    return np.array([df_dx, df_dy])

def steepest_descent(initial_vars, num_iterations):
    vars_values = [initial_vars]
    f_values = [objective_function(initial_vars)]
    for _ in range(num_iterations):
        current_vars = vars_values[-1]
        descent_direction = -gradient(current_vars)
        step_size = minimize_scalar(lambda alpha: objective_function(current_vars + alpha * descent_direction)).x
        new_vars = current_vars + step_size * descent_direction
        vars_values.append(new_vars)
        f_values.append(objective_function(new_vars))
    return vars_values, f_values

initial_vars = np.array([-3, 1])
num_iterations = 20
vars_values, f_values = steepest_descent(initial_vars, num_iterations)

print("Optimal variables:", vars_values[-1])
print("Optimal objective value:", f_values[-1])

x = np.linspace(-5, 1, 100)
y = np.linspace(-2, 2, 100)
X, Y = np.meshgrid(x, y)
Z = objective_function([X, Y])

plt.contour(X, Y, Z, levels=np.linspace(Z.min(), Z.max(), 20), cmap='viridis')
plt.scatter(*zip(*vars_values), color='red', label='Steepest Descent Path')
plt.title('Steepest Descent Optimization')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()
