from scipy.optimize import minimize

def objective_function(vars):
    x, y = vars
    return 3*x**2 + 2*y**2

def constraint1(vars):
    x, y = vars
    return x + y - 5

def constraint2(vars):
    x, y = vars
    return 4 - 2*x + y

initial_guess = [0, 0]

bounds = [(0, None), (0, None)]

constraints = [
    {'type': 'ineq', 'fun': constraint1},
    {'type': 'ineq', 'fun': constraint2}
]

result = minimize(objective_function, initial_guess, bounds=bounds, constraints=constraints)

if result.success:
    print("Optimal values:", result.x)
    print("Optimal objective value:", result.fun)
else:
    print("Optimization failed:", result.message)
