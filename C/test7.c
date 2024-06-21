#include <stdio.h>

int main(void)
{
    int x;
    printf("enter your nuber here -->  ");
    scanf("%d", &x);
    while (x) /*все истина кроме 0*/
    {
        if (x%2 == 0) printf("Number %d is even\n", x);
        else printf("Number %d is odd\n", x);
        printf("enter your nuber here -->  ");
        scanf("%d", &x);
    }

    printf("programm finished with exit code 0\n");
    return 0;
}