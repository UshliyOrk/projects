#include <stdio.h>
#include <iso646.h>

// эта функция изменит сам массив и вернет уровень заполнения
// БУФЕР МАССИВА ДОЛЖЕН БЫТЬ ДОСТАТОЧНЫМ
int getFactors(int x, int A[])
{
    int top = 0;
    if (x == 0)
    {
        A[top] = 0;
        top ++;
    }
    int divisor = 2;
    while (x!=1)
    {
        while (x%divisor == 0)
        {
            A[top] = divisor;
            top ++;
            x/=divisor;
        }
        divisor ++;
    }
    
    return top;
}

int main(void)
{
    int x, N;
    int A[100];
    printf("Enter a Number to facroeize --> ");
    scanf("%d", &x);

    N = getFactors(x, A);
    
    for (int i = 0; i < N; i++) printf("%d ", A[i]);
}