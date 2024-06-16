import tkinter as tk
from random import choice
from time import sleep


def create_circle(x, y, my_canvas, r=1):
    x0 = x-r
    y0 = y-r
    y1 = y+r
    x1 = x+r
    return my_canvas.create_oval(x0, y0, x1, y1, fill="red", outline="black")


window = tk.Tk()
window.title("треугольник Серпинского")
window.geometry("400x400")

text = tk.StringVar()
label = tk.Label(textvariable=text)
label.pack()
firstDots = [(200, 50), (50, 350), (350, 350)]
canvas = tk.Canvas(bg="white", width=1000, height=1000)
canvas.pack(expand=1, anchor=tk.CENTER)

for i in firstDots:
    create_circle(i[0], i[1], canvas)

nextDot = [(firstDots[0][0]+firstDots[2][0])//2, (firstDots[0][1]+firstDots[2][1])//2]
create_circle(nextDot[0], nextDot[1], canvas)

for i in range(1000000000000000):
    lastDot = nextDot
    dot = choice(firstDots)
    nextDot = [(lastDot[0]+dot[0])//2, (lastDot[1]+dot[1])//2]
    create_circle(nextDot[0], nextDot[1], canvas)
    window.update()
    sleep(0.001)
window.title("треугольник Серпинского (Готово!)")
text.set("Готово")

window.mainloop()
