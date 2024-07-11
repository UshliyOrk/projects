// адреса и указатели
#include <stdio.h>

int main(void)
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = A+7;
    int *q = A+5;

    //операции взятия адреса и разыменования - взаимоисключающие
    for (int i = 0; i < 5; i++)
    {
        printf("*(A+i) = %d\n", *(A+i));// массив = указатель + выедленная память
        printf("A[i] = %d\n", A[i]);
    }
    
    printf("*p = %d\n", *p);
    printf("p[-1] = %d\n", p[-1]);
    printf("p[0] = %d\n", p[0]);
    printf("p[1] = %d\n", p[1]);

    if (q>p) printf("q > p\n");
    else printf("q <= p\n");

    printf("p-q = %d", p-q);

    return 0;
}