#include <stdio.h>

int main(void)
{
    int start, stop, step;
    int sign;

    scanf("%d %d %d", &start, &stop, &step);

    sign = (step>0)? +1:-1;
    if (step == 0) sign = 0;

    while (sign*start<sign*stop)
    {
        printf("%d\n", start);
        start += step;
    }
    printf("%d\n", start);
    return 0;
}