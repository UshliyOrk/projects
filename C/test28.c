// адреса и указатели
#include <stdio.h>

int main(void)
{
    int i = 10;//переменная
    int *pi = &i;// указатель(pointer) адресного типа(*) на переменную i (&i - адрес переменной в памяти)
    int **ppi = &pi;// указатель на указатель
    int ***pppi = &ppi;// указатель на указатель на указатель

    printf("%d\n", i);
    *pi = 20; // разыменование
    printf("%d\n", i);
    **ppi = 30; // двойное разыменование
    printf("%d\n", i);
    ***pppi = 40;
    printf("%d\n", i);

    return 0;
}