from matplotlib.pyplot import title, xlabel, ylabel, grid, plot, show, savefig
import numpy as np
import sympy as sp
from math import pi


class Plotter:
    a = -pi
    b = pi

    def functions(self, func1, func2):
        self.g1 = sp.sympify(func2)
        x = sp.symbols("x")
        self.g = sp.lambdify(x, self.g1, "numpy")
        self.f1 = sp.sympify(func1)
        x = sp.symbols("x")
        self.f = sp.lambdify(x, self.f1, "numpy")

    def search(self):
        x = sp.symbols("x")
        return sp.solve(self.f1-self.g1, x)

    def funcArea(self):
        x = sp.symbols('x')
        a1 = self.l[0]
        b1 = self.l[1]
        return round(sp.integrate(self.f1 - self.g1, (x, a1, b1)), self.eps)

    def funcPlot(self):
        # Независимая (x) и зависимая (y) переменные
        x = np.linspace(self.a, self.b, 50)
        y1 = self.g(x)
        y2 = self.f(x)
        # Построение графика
        title('здесь могла быть ваша реклама')  # заголовок
        xlabel('x')  # ось абсцисс
        ylabel('y')  # ось ординат
        grid()  # включение отображение сетки
        plot(x, y1, x, y2)  # построение графика
        savefig("plt.png")
        show()


if __name__ == "__main__":
    app = Main()
    fnc1, fnc2 = input().split()
    app.functions(fnc1, fnc2)
    # print(round(app.funcArea(), 3))
    app.funcPlot()
