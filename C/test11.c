#include <stdio.h>

void break_continue_usage()
{
    while (1)
    {
        int x;
        printf("enter your number Here --> ");
        scanf("%d", &x);
        if (x==0) break;
        else if (x<0)
        {
            printf("I do not work with negarive numbers\n");
            continue;
        }

        printf("number %d in hex is %X.\n", x, x);
    }
    
}

int is_prime(int x)
{
    int divisor;
    if (x<0) return 0;
    for(divisor = 2; divisor*divisor <= x; ++divisor)
        if (x%divisor == 0) return 0;
    return 1;
}

int main(void)
{
    int x;
    //break_continue_usage();
    while (1)
    {
        printf("enter your number Here --> ");
        scanf("%d", &x);
        if (x == 0) break;
        if (is_prime(x)) printf("Number %d is prime\n", x); 
        else printf("Number %d is not prime\n", x);
    }
    
    printf("programm finished with exit code 0\n");
    return 0;
}
