import sympy as sp

def taylor_polynomial(function, variable, center, degree):
    taylor_series = sp.series(function, variable, center, degree + 1).removeO()
    taylor_poly = sp.Poly(taylor_series, variable)
    return taylor_poly

def main():
    x = sp.symbols('x')
    function = sp.sin(x)
    center = 0
    degree = 4
    taylor_poly = taylor_polynomial(function, x, center, degree)
    print(f"Original function: {function}")
    print(f"Taylor polynomial of degree {degree} centered at {center}: {taylor_poly}")

if __name__ == "__main__":
    main()
