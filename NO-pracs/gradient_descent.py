import numpy as np
import matplotlib.pyplot as plt

def objective_function(x):
    return x**2 + 5

def gradient(x):
    return 2 * x

def gradient_descent(initial_x, learning_rate, num_iterations):
    x_values = [initial_x]
    y_values = [objective_function(initial_x)]

    for _ in range(num_iterations):
        current_x = x_values[-1]
        update = learning_rate * gradient(current_x)
        new_x = current_x - update

        x_values.append(new_x)
        y_values.append(objective_function(new_x))

    return x_values, y_values

initial_x = -10
learning_rate = 0.1
num_iterations = 50

x_values, y_values = gradient_descent(initial_x, learning_rate, num_iterations)

print("Optimal x:", x_values[-1])
print("Optimal objective value:", y_values[-1])
    
x = np.linspace(-12, 12, 100)
y = objective_function(x)

plt.plot(x, y, label='Objective Function: $f(x) = x^2 + 5$')
plt.scatter(x_values, y_values, color='red', label='Gradient Descent Path')
plt.title('Gradient Descent Optimization')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.show()
