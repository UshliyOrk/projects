import sympy
from func import f, g

a = -2.356
b = 0.785
x = sympy.Symbol('x')
print(sympy.integrate(f(x)-g(x), (x, a, b)))



