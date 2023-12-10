def newton_method(func, derivative, initial_guess, tolerance=1e-10, max_iterations=1000):
    x = initial_guess
    iterations = 0
    
    while abs(func(x)) > tolerance and iterations < max_iterations:
        x = x - func(x) / derivative(x)
        iterations += 1
    
    if abs(func(x)) <= tolerance:
        return x, iterations
    else:
        return None, iterations

def func(x):
    return x**3 - x - 2

def derivative(x):
    return 3*x**2 - 1

initial_guess = 2.0

root, iterations = newton_method(func, derivative, initial_guess)

if root is not None:
    print(f"Root found: {root} after {iterations} iterations")
else:
    print("Newton's method did not converge to a root.")
