from math import cos, sin, pi

def ak (k):
	a = ((-1)**k*4)/(k**2)
	return a

def bk (k):
	b = 0
	return b

def f (x):
	y = x**2
	return y


def row (N, x):
	a0 = 2*pi**2/3
	y_ref = f(x)
	y = a0/2
	for i in range(1, N):
		ai = ak(i)
		bi = bk(i)
		y += ai*cos(i*x) + bi*sin(i*x)

	return (y_ref, y)


result = row(1000000, 2)
print(result)
