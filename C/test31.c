#include <stdio.h>

void f1(int a)
{
    printf("got: a = %d\n", a);
    a += 10;
    printf("did: a = %d\n", a);
}

void f2(int *p)
{
    printf("got: *p = %d\n", *p);
    *p += 10;
    printf("did: *p = %d\n", *p);
}

int main (void)
{
    int x = 7;
    printf("x = %d\n", x);
    f1(x); // эта функция сам икс не меняет
    printf("x = %d\n", x);
    f2(&x);// а эта меняет
    printf("x = %d\n", x);

    return 0;
}