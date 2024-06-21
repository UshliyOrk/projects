#include <stdio.h>
#include <iso646.h>

int main (void)
{
    int x, y;
    printf("enter coordinates x y Here --> ");
    scanf("%d %d", &x, &y);

    while (1)
    {
        if (x == 0 and y == 0) break;
        if (y>0 and x>0) printf("your dot is in first quarter\n");
        else if (y>0 and x<0) printf("your dot is in second quarter\n");
        else if (y<0 and x<0) printf("your dot is in third quarter\n");
        else if (y<0 and x>0) printf("your dot is in fourth quarter\n");
        else printf("dot is on axis\n");

        printf("enter coordinates x y Here --> ");
        scanf("%d %d", &x, &y);
    }

    return 0;
}