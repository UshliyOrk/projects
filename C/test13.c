#include <stdio.h>
#include <iso646.h>

int main(void)
{
    int x;
    printf("number to split on digits --> ");
    scanf("%d", &x);
    while (x)
    {
        int digit = x%10;
        if (not(digit%2))
        {
            printf("%d ", digit);
        }
        x /= 10;
    }
    
    return 0;
}