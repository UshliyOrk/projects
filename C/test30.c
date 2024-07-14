#include <stdio.h>
#include <stdlib.h>// для exit()

void print_abstarct(void *p, int type_marker);

int main (void)
{
    void *p; // указатель без типа
    int i = 10;
    char c = 'A';
    double d = 3.14;

// может хранить указатель на любой тип данных
// разыменовать указатель типа void нельзя
    p = &c;
    printf("%c\n", *(char*)p); //явное приведение, потом разыменование

    p = &i;
    print_abstarct(p, 1);
    p = &d;
    print_abstarct(p, 2);
    print_abstarct(p, 4);

    return 0;
}

//use case
void print_abstarct(void *p, int type_marker)
{
    if (type_marker == 1) printf("%d\n", *(int*)p);
    else if (type_marker == 2) printf("%lf\n", *(double*)p);
    else if (type_marker == 3) printf("%c\n", *(char*)p);
    else
    {
        printf("Unknown type\n");
        exit(1);
    }
}