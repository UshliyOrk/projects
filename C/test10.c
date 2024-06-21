#include <stdio.h>

int func1_goto_usage(void)
{
    int x;
    A: 
        printf("enter your number Here --> ");
        scanf("%d", &x);
        if  (x==0) goto D;
    B: 
        if (x%2 != 0) goto C;
        printf("your number is even\n");
        goto A;
    C:
        printf("your number is odd\n");
        goto A;

    D:
        return 0;
}

int func2_switch_case_usage(void)
{
    int x;
    printf("x = ");
    scanf("%d", &x);
    while (x)
    {
        switch (x)
        {
        case 1: printf("one\n"); break; 
        case 2:printf("two\n"); break;
        case 3: printf("three\n"); break;
        case 4:printf("four\n"); break;
        default:printf("Don't know this number...\n");
        }
        printf("x = ");
        scanf("%d", &x);
    }
    
    return 0;
}

int main(void)
{
    int mode;
    printf("select function to use -->  ");
    scanf("%d", &mode);
    if (mode == 1) func1_goto_usage();
    else func2_switch_case_usage();

    printf("programm finished with exit code 0\n");
    return 0;
}


/*
в нормальных случаях метки и goto, switch заменимы циклами и ветвлением. их использование приводит к
ухудшению читаемости кода. switch не удобен тем, что выполняет все кейсы, если они бе брейка.
так же, свитч принимает исключительно целые числа
*/