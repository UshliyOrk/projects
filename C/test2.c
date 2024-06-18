#include <stdio.h>

int main(void)
{
    int i;
    for(i= 10; i>=0; --i)
    {
        printf("%d\n", i);
    }
    /*i = -1*/
    while (i < 10)
    {
        printf("%d\n", i);
        ++i;
    }
    /*i = 10*/
}