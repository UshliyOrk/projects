from func import f, g
from math import pi
eps = 3
a = round(-pi*10**eps)
b = round(pi*10**eps)
for x in range(a, b, 1):
    if round(f(x/10**eps), eps) == round(g(x/10**eps), eps):
        print(x/10**eps)
