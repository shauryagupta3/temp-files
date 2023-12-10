import sympy as sp

x1, x2 = sp.symbols('x1 x2')

f = 100 * (x2 - x1**2)**2 + (1 - x1)

gradient = [sp.diff(f, x1), sp.diff(f, x2)]

hessian = [[sp.diff(gradient[0], x1), sp.diff(gradient[0], x2)],
           [sp.diff(gradient[1], x1), sp.diff(gradient[1], x2)]]

print("Gradient of f(x):", gradient)
print("Hessian of f(x):", hessian)
