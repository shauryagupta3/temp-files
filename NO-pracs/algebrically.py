from scipy.optimize import minimize
import numpy as np

def derivative(x):
    return 10 * np.pi * np.sin(np.pi * x - 2.2) + x + 1.5

critical_points = minimize(derivative, x0=0, method='BFGS')
optimal_x = critical_points.x[0]
optimal_value = -10 * np.cos(np.pi * optimal_x - 2.2) + (optimal_x + 1.5) * optimal_x

print("Global Optimal Solution (Algebraic): x =", optimal_x, ", f(x) =", optimal_value)
