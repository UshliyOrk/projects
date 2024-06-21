#include <stdio.h>

int main(void)
{
    int x, y;
    printf("enter coordinates x y Here --> ");
    scanf("%d %d", &x, &y);

    while (1)
    {
        if (x==0 && y==0) break;
        if (x > 0)
        {
            if (y>0) printf("your dot is in first quarter\n");
            else printf("your dot is in fourth quarter\n");
        }
        else
        {
            if(y>0) printf("your dot is in second quarter\n");
            else printf("your dot is in third quarter\n");
        }
        printf("enter coordinates x y Here --> ");
        scanf("%d %d", &x, &y);
    }
    

    return 0;
}