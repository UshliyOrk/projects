#include <stdio.h>

int main (void) // что-то можно передать при вызове из термнала (int argc, char* argv[])
{
    int i = 0, size , x = 12345, y;
    int num[5];

    while (x!=0)
    {   
        num[i] = x%10;
        printf("%d\n", num[i]);
        x = x/10;
    }

    size = sizeof(num)/sizeof(int); // длинна исходного массива
    printf("%d\n", size);
    
    x = 12;
    y = 7;
    printf("%lf\n", (double)x / y); //для дробого деления хотя бы одно число должно быть дробного типа
    printf("%lf\n", 1./2);// 1. - сокращение от 1.0
    return 0; 
}