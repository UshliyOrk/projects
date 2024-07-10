#include <stdio.h>

// declare объявление функции но без ее описания
// функции не обязательно объявлять отдельно, это происходит вместе с описанием
void a();
void b();
void c();

//Функции исполняются одна за другой
int main (void)
{
    printf("main() called\n");
    printf("main() -> ");
    a();
    printf("main() returns\n");

    return 0;
}

// define описание функции
void a()
{
    printf("A() called\n");
    printf("A() -> ");
    b();
    printf("A() -> ");
    c();
    printf("A() returns\n");
}

void b()
{
    printf("B() called\n");
    printf("B -> ");
    c();
    printf("B() returns\n");
}

void c()
{
    printf("C() called\n");
    printf("C() returns\n");
}