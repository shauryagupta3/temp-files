import numpy as np

def f(x):
    return x**2

def f_prime(x):
    return 2*x

def line_search(x, direction, alpha=0.1, beta=0.7):
    t = 1.0
    while f(x + t * direction) > f(x) + alpha * t * np.dot(f_prime(x), direction):
        t *= beta
    return t

def gradient_descent(starting_point, epsilon=1e-5, max_iterations=1000):
    x = starting_point
    iterations = 0
    while np.linalg.norm(f_prime(x)) > epsilon and iterations < max_iterations:
        direction = -f_prime(x)
        step_size = line_search(x, direction)
        x = x + step_size * direction
        iterations += 1
    return x, f(x)

starting_point = 5.0
optimal_point, optimal_value = gradient_descent(starting_point)

print(f"Optimal Point: {optimal_point}")
print(f"Optimal Value: {optimal_value}")
