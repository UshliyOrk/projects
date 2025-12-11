import pyautogui
from time import sleep

sleep(2)
for i in range (70):
    pyautogui.click(x=1590, y=180+(i**(1.5)))
    pyautogui.click(x=1890, y=180)
    sleep(1)
