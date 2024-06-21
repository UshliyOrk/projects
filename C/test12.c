#include<stdio.h>

void print_factors(int num)
{
    printf("Number of factors: ");
    if (num == 0)
    {
        printf("0\n");
        return;
    }
    int divisor = 2;
    while (num!=1)
    {
        while (num%divisor == 0)
        {
            printf("%d ", divisor);
            num /= divisor;
        }
        divisor += 1;
    }
    printf("\n");
}

int main(void)
{
    int x;
    printf("enter your number --> ");
    scanf("%d", &x);
    print_factors(x);

    return 0;
}