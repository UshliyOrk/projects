from matplotlib.pyplot import title, xlabel, ylabel, grid, plot, show
import numpy as np
import sympy as sp
from math import pi

class Main:
    eps = 3
    a = -pi
    b = np.pi
    def g(self, x):
        try:
            y = np.sin(x)
        except:
            y = sp.sin(x)
        return y


    def f(self, x):
        try:
            y = np.cos(x)
        except:
            y = sp.cos(x)
        return y
    def search(self):
        self.l = []
        a = round(self.a * 10 ** self.eps)
        b = round(self.b * 10 ** self.eps)
        for x in range(a, b, 1):
            if round(self.f(x / 10 ** self.eps), self.eps) == round(self.g(x / 10 ** self.eps), self.eps):
                self.l.append(x / 10 ** self.eps)
        return self.l

    def funcArea(self):
        x = sp.Symbol('x')
        a1 = self.l[0]
        b1 = self.l[1]
        return sp.integrate(self.f(x) - self.g(x), (x, a1, b1))

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
        show()


if __name__ == "__main__":
    app = Main()
    L = app.search()
    print(L)
    print(round(app.funcArea(), 3))
    app.funcPlot()
