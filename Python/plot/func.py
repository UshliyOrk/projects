import numpy as np
import sympy as sp

# задаю функции дважды потому что sympy не хавает функции из numpy
def g(x):
    try:
        y = np.sin(x)
    except:
        y = sp.sin(x)
    return y


def f(x):
    try:
        y = np.cos(x)
    except:
        y = sp.cos(x)
    return y

