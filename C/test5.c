#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int x;
    bool y;

    printf("%d\n", 5 > -1); /*логика возвращает целое число*/
    printf("%d\n", 5u > -1);
    /*знаковый инт при сравнении приводится к беззнаковому отсюда и ошибка*/
    x = (1!=0) + 1;
    y = (4 == 2+2) + 1; /*выглядит так же, но арифметика не работает*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}