#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Nov 21 15:11:55 2020

@author: paul
"""
import random
from collections import Counter

a=int(input('положите деньги на счет:'))
def start (a):
    q=''
    print('********************************************')
    print('приветствую тебя в нашем казино, дружище!')
    print('********************************************')
    print("у тебя на счету: ",a)
    print("ты можешь сыграть в: ")
    print("    1.рулетку")
    print("    2.кости")
    print("    3.однорукого бандита")
    print('    4.камень, ножницы, бумага')
    print("    0.выход")
    b=input("твой выбор...")
    if b=='0':
        return
    while q=='' and a>0:
        if b=='1':
            print("------------------------------------------")
            print("РУЛЕТКА")
            print("------------------------------------------")
            print()
            print("счет",a)
            print("ставлю на...")
            print("    1.четное(1:1)")
            print("    2.нечетное(1:1)")
            print("    3.дюжина(3:1)")
            print("    4.свое число(1:36)")
            print("0.выход в пердыдушее меню")
            c=int(input('твой выбор...'))
            if c == 0:
                start(a)
            if c== 1:
                w=int(input("твоя ставка: "))
                e=random.randint(1,36)
                if e%2==0:
                    print("ты выиграл ,твой счет:",a)
                else:
                    a=a-w
                    print("ты проиграл,твой счет:",a)
                q=input('enter чтобы продолжить, 0-главное меню')
            if c== 2:
                w=int(input("твоя ставка: "))
                e=random.randint(1,36)
                if e%2==1:
                    print("ты выиграл ,твой счет:",a)
                else:
                    a=a-w
                    print("ты проиграл,твой счет:",a)
                q=input('enter чтобы продолжить, 0-главное меню')
            if c==3:
                w=int(input("твоя ставка: "))
                a=a-w
                e=random.randint(1,36)
                if e%12==0:
                    a=a+3*w
                    print("ты выиграл ,твой счет:",a)
                else:
                    print("ты проиграл,твой счет:",a)
                q=input('enter чтобы продолжить, 0-главное меню')
            if c==4:
                w=int(input("твоя ставка: "))
                r=int(input("твое число: "))
                a=a-w
                e=random.randint(1,36)
                if e==r:
                    a=a+36*w
                    print("ты выиграл ,твой счет:",a)
                else:
                    print("ты проиграл,твой счет:",a)
                q=input('enter чтобы продолжить, 0-главное меню')
        if b == '2':
            print('------------------')
            print('КОСТИ')
            print('------------------')
            print('')
            f=random.randint(1,6)
            g=random.randint(1,6)
            print('----- -----')
            print('|',f,'|','|',g,'|')
            print('----- -----')
            o1=f+g
            print("счет",a)
            print()
            print('текущая сумма чисел: ',o1)
            print('')
            print('семма чисел на гранях будет больше, меньше или равна текущей')
            print('1-больше, 2-меньше, 3-равно, 0-выход')
            print('')
            answ=int(input('твой вариант...'))
            if answ== 0:
                start(a)
            elif answ ==1:
                w=int(input('ставка: '))
                a=a-w
                f=random.randint(1,6)
                g=random.randint(1,6)
                print('----- -----')
                print('|',f,'|','|',g,'|')
                print('----- -----')
                o2=f+g
                if o2>o1:
                    a=a+w*2
                    print("ты выиграл ,твой счет:",a)
                else:
                    print("ты проиграл,твой счет:",a)
                q=input('enter чтобы продолжить, 0-главное меню')
            elif answ ==2:
                w=int(input('ставка: '))
                a=a-w
                f=random.randint(1,6)
                g=random.randint(1,6)
                print('----- -----')
                print('|',f,'|','|',g,'|')
                print('----- -----')
                o2=f+g
                if o2<o1:
                    a=a+w*2
                    print("ты выиграл ,твой счет:",a)
                else:
                    print("ты проиграл,твой счет:",a)
                q=input('enter чтобы продолжить, 0-главное меню')
            elif answ ==3:
                w=int(input('ставка: '))
                a=a-w
                f=random.randint(1,6)
                g=random.randint(1,6)
                print('----- -----')
                print('|',f,'|','|',g,'|')
                print('----- -----')
                o2=f+g
                if o2==o1:
                    a=a+w*10
                    print("ты выиграл ,твой счет:",a)
                else:
                    print("ты проиграл,твой счет:",a)
                q=input('enter чтобы продолжить, 0-главное меню')
        if b=='3':
            print('***********************')
            print('ОДНОРУКИЙ БАНДИТ')
            print('***********************')
            print('')
            print('у тебя на счету: ',a)
            print('')
            print('правила игры:')
            print("    1.при совпадении двух чисел ставка не списывается")
            print('    2.совпало 3-х2')
            print('    3.совпало 4-х5')
            print('    4.совпало 5-х10')
            print('')
            w=int(input('ставка: '))
            a=a-w
            u=random.randint(3,9)
            i=random.randint(3,9)
            k=random.randint(3,9)
            l=random.randint(3,9)
            m=random.randint(3,9)
            print('%%%%%%%%%%%')
            print(u,i,k,l,m)
            r=[u,i,k,l,m]
            t=Counter(r)
            h=[]
            for i in range(3,10):
                h.append(t[i])
            if max(h)<=1:
                print("ты проиграл,твой счет:",a)
            elif max(h)==2:
                a=a+w
                print("ты выиграл ,твой счет:",a)
            elif max(h)==3:
                a=a+w*2
                print("ты выиграл ,твой счет:",a)
            elif max(h)==4:
                a=a+w*5
                print("ты выиграл ,твой счет:",a)
            elif max(h)==5:
                a=a+w*10
                print("ты выиграл ,твой счет:",a)
            q=input('enter чтобы продолжить, 0-главное меню')
        if b=='4':
            print("^^^^^^^^^^^^^^^^^^^^^^^")
            print("Камень ножници бумага")
            print("^^^^^^^^^^^^^^^^^^^^^^^")
            print("")
            print("У тебя на счету: ",a)
            print("")
            print("1.камень, 2.ножници, 3.бумага")
            g=int(input("что ты выкенешь?..."))
            j=random.randint(1,3)
            w=int(input("твоя ставка: "))
            a-=w
            if g==1 and j==1:
                print("ничия, твой счет прежний")
                a+=w
            elif g==2 and j==2:
                print("ничия, твой счет прежний")
                a+=w
            elif g==3 and j==3:
                print("ничия, твой счет прежний")
                a+=w
            elif g==1 and j==2:
                print("ты выиграл, твой счет: ",a)
                a+=w*3
            elif g==2 and j==3:
                print("ты выиграл, твой счет: ",a)
                a+=w*3
            elif g==3 and j==1:
                print("ты выиграл, твой счет: ",a)
                a+=w*3
            elif g==2 and j==1:
                print("ты проиграл, твой счет: ",a)
            elif g==3 and j==2:
                print("ты проиграл, твой счет: ",a)
            elif g==1 and j==2:
                print("ты проиграл, твой счет: ",a)
            q=input("enter чтобы продолжить, 0-главное меню")
    start(a)
print('$$$$$$$$$$$$$$$$$$$$$$')
b=start(a)