#include <stdio.h>

int main(void)
{
    unsigned int x, y;
    int z;
    z=x=y=-5;/*внезапно беззнаковый инт стал знаковым*/
    printf(" x  y  z\n");
    printf("%d %d %d\n", x, y,z);
    x = 64;
    printf("x = %d\n", x);
    x*=2;
    printf("x = %d\n", x);
    x+=16;
    printf("x = %d\n", x);
    x/=7;
    printf("x = %d\n", x);
    x-=33;
    printf("x = %d\n", x);

    printf("x > y = %d\n", x>y);

    return 0;
}